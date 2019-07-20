#include "DSP28x_Project.h"
#include "drivers/spi.h"
#include "drivers/mcbsp.h"
#include "libs/safepipe/safepipe_rx.h"
#include "libs/complex/complex.h"

#include <string.h>

int16 sx1255_rx_overrun = 0;

#pragma DATA_SECTION(sx1255_rx_buffer,"DMARAML47");
short_complex_t sx1255_rx_buffer[4][512];

safepipe_rx_t sx1255_rx_pipe;

const void *sx1255_rx_buf_p[4] = {sx1255_rx_buffer[0],sx1255_rx_buffer[1],sx1255_rx_buffer[2],sx1255_rx_buffer[3]};

#pragma CODE_SECTION(sx1255_rx_alloc_buffer,"ramfuncs");
int16 sx1255_rx_alloc_buffer(short_complex_t ** buff_p)
{
    if(safepipe_rx_readable(&sx1255_rx_pipe))
    {
        safepipe_rx_read_update(&sx1255_rx_pipe);

        *buff_p = safepipe_rx_get_current_read_buf(&sx1255_rx_pipe);

        return 1;
    }
    else
    {
        return 0;
    }
}

void sx1255_rx_release_buffer(short_complex_t * buff_p)
{
    return;
}

void sx1255_rx_reset_state(void)
{
    Uint16 *new_buf;
    memset(sx1255_rx_buffer,0,sizeof(sx1255_rx_buffer));
    safepipe_rx_init(&sx1255_rx_pipe,4,(void **)sx1255_rx_buf_p);
    new_buf = safepipe_rx_get_ori_write_buf(&sx1255_rx_pipe);
    EALLOW;
    DmaRegs.CH1.DST_ADDR_SHADOW = (Uint32)new_buf;
    DmaRegs.CH1.DST_BEG_ADDR_SHADOW = (Uint32)new_buf;
    EDIS;
}

#pragma CODE_SECTION(SX1255_RX_DMA_ISR,"ramfuncs");
interrupt void SX1255_RX_DMA_ISR(void)     // DMA Ch1 - McBSP-A Rx
{
    Uint16 *new_buf;
    if(safepipe_rx_writeable(&sx1255_rx_pipe))
    {
        safepipe_rx_write_update(&sx1255_rx_pipe);
        new_buf = safepipe_rx_get_current_write_buf(&sx1255_rx_pipe);
        EALLOW;
        DmaRegs.CH1.DST_ADDR_SHADOW = (Uint32)new_buf;
        DmaRegs.CH1.DST_BEG_ADDR_SHADOW = (Uint32)new_buf;
        EDIS;
    }
    else
    {
    	sx1255_rx_overrun = 1;
    }

    EALLOW;
    //DmaRegs.CH1.CONTROL.bit.RUN = 1; // Start rx on Channel 1

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;// To receive more interrupts from this PIE group, acknowledge this interrupt
    EDIS;
}
