/****************************************************************************************
* ALI SAHBAZ
*
*
* ASZ Framework
*
* Date          : 05.07.2023
* By            : Ali Þahbaz
* e-mail        : ali_sahbaz@outlook.com
*/
#include <stdio.h> 
#include <stdlib.h> 
#include "main.h"

//#include "bridge_pattern_test.h"

#include "bridge.h"
#include "wifi_comm.h"
#include "usb_comm.h"
 

int main(void)
{
    printf("Starting ... \n\n");

    //bridge_pattern_test_run();

    wifi_obj_t wifi;
    usb_obj_t usb;

    wifi_obj_t wifi2;
    usb_obj_t usb2;
     
    wifi_comm_create(&wifi );
    usb_comm_create(&usb );

    wifi_comm_create(&wifi2);
    usb_comm_create(&usb2);

    /** !! wifi must be first pile , first call , to init and for obj struct construction **/
    BRIDGE_OBJ_CREATE(bridge_area_1);
    BRIDGE_CONNECTION_ASSIGN(bridge_area_1, usb_to_wifi_bridge, wifi , usb );

    usb_comm_process(&usb);
    wifi_comm_process(&wifi);

    BRIDGE_OBJ_CREATE(bridge_area_2);
    BRIDGE_CONNECTION_ASSIGN(bridge_area_2, usb_to_wifi_bridge, wifi2, usb2);

    usb_comm_process(&usb2);
    wifi_comm_process(&wifi2);
   

    return 0;
}