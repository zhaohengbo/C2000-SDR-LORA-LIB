#include "DSP28x_Project.h"
#include "app/init.h"
#include "drivers/sx1255.h"
#include "libs/lora/lora_tx.h"
#include "libs/lora/lora_rx.h"
#include "libs/lora/lora_frame.h"
#include "libs/link/link_rx.h"
#include "libs/link/link_tx.h"

void main(void)
{
    DeviceInit();
    //link_tx_layer_init();
    link_rx_layer_init();
    sx1255_dms_start_rx();
    //sx1255_dms_start_tx();
    EINT;
    ERTM;
    while(1)
    {
        //lora_tx_loop();
        //link_tx_loop();
        lora_rx_loop();
        link_rx_loop();
    }
}
