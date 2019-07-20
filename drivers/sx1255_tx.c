#include "DSP28x_Project.h"
#include "drivers/spi.h"
#include "drivers/mcbsp.h"
#include "libs/safepipe/safepipe_tx.h"
#include "libs/complex/complex.h"

#include <string.h>

int16 sx1255_tx_overrun = 0;

#pragma DATA_SECTION(sx1255_tx_buffer,"DMARAML47");
short_complex_t sx1255_tx_buffer[4][512];

safepipe_tx_t sx1255_tx_pipe;

const void *sx1255_tx_buf_p[4] = {sx1255_tx_buffer[0],sx1255_tx_buffer[1],sx1255_tx_buffer[2],sx1255_tx_buffer[3]};

#pragma CODE_SECTION(sx1255_tx_alloc_buffer,"ramfuncs");
int16 sx1255_tx_alloc_buffer(short_complex_t ** buff_p)
{
    if(safepipe_tx_writeable(&sx1255_tx_pipe))
    {
        *buff_p = safepipe_tx_get_current_write_buf(&sx1255_tx_pipe);
        return 1;
    }
    else
    {
        return 0;
    }
}

void sx1255_tx_release_buffer(short_complex_t * buff_p)
{
    safepipe_tx_write_update(&sx1255_tx_pipe);
}

void sx1255_tx_reset_state(void)
{
    Uint16 *new_buf;
    memset(sx1255_tx_buffer,0,sizeof(sx1255_tx_buffer));
    safepipe_tx_init(&sx1255_tx_pipe,4,(void **)sx1255_tx_buf_p);
    new_buf = safepipe_tx_get_ori_read_buf(&sx1255_tx_pipe);
    EALLOW;
    DmaRegs.CH2.SRC_ADDR_SHADOW = (Uint32)new_buf;
    DmaRegs.CH2.SRC_BEG_ADDR_SHADOW = (Uint32)new_buf;
    EDIS;
}

#pragma CODE_SECTION(SX1255_TX_DMA_ISR,"ramfuncs");
interrupt void SX1255_TX_DMA_ISR(void)     // DMA Ch2 - McBSP-A Tx
{
    Uint16 *new_buf;

    if(safepipe_tx_readable(&sx1255_tx_pipe))
    {
        safepipe_tx_read_update(&sx1255_tx_pipe);
        new_buf = safepipe_tx_get_current_read_buf(&sx1255_tx_pipe);

        EALLOW;
        DmaRegs.CH2.SRC_ADDR_SHADOW = (Uint32)new_buf;
        DmaRegs.CH2.SRC_BEG_ADDR_SHADOW = (Uint32)new_buf;
        EDIS;
    }
    else
    {
    	sx1255_tx_overrun = 1;
    }

    EALLOW;
    //DmaRegs.CH2.CONTROL.bit.RUN = 1; // Start tx on Channel 2

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP7; // To receive more interrupts from this PIE group, acknowledge this interrupt
    EDIS;
}
