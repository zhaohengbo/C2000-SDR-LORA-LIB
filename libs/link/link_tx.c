#include "DSP28x_Project.h"
#include "libs/safepipe/safepipe.h"
#include "libs/lora/lora_frame.h"

#include <string.h>
#include <stdlib.h>

lora_frame_t link_tx_buffer[4];

safepipe_t link_tx_pipe;

const void *link_tx_buf_p[4] = {&link_tx_buffer[0],&link_tx_buffer[1],&link_tx_buffer[2],&link_tx_buffer[3]};

void link_tx_layer_init(void)
{
    memset(link_tx_buffer,0,sizeof(link_tx_buffer));
    safepipe_init(&link_tx_pipe,4,(void **)link_tx_buf_p);
}

#pragma CODE_SECTION(link_tx_layer_send_cb,"ramfuncs");
int16 link_tx_layer_send_cb(lora_frame_t * send_frame)
{
    lora_frame_t *new_frame;
    if(safepipe_readable(&link_tx_pipe))
    {
        safepipe_read_update(&link_tx_pipe);
        new_frame = safepipe_get_current_read_buf(&link_tx_pipe);
        memcpy(send_frame,new_frame,sizeof(lora_frame_t));
        return 1;
    }
    return 0;
}

Uint16 test_send = 1;
Uint16 test_count = 0;

#pragma CODE_SECTION(link_tx_loop,"ramfuncs");
void link_tx_loop(void)
{
    lora_frame_t *new_frame;
    int i;

    if(test_send == 1)
    {
        test_count++;
        if(test_count < 500)
        {
            return;
        }
        else
        {
            test_count = 0;
        }
    }
    else
    {
        return;
    }

    if(safepipe_writeable(&link_tx_pipe))
    {
        new_frame = safepipe_get_current_write_buf(&link_tx_pipe);

        //send here
        new_frame->src_addr = 0x33;
        new_frame->dst_addr = 0xCC;
        new_frame->type = 0x44;
        new_frame->length = 32;
        for(i=0;i<32;i++)
        {
            new_frame->data[i] = (rand() & 0xFF);
        }

        safepipe_write_update(&link_tx_pipe);
    }
}
