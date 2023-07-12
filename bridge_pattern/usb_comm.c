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
#include "usb_comm.h"

#include "wifi_comm.h" // for reach

void usb_comm_create(usb_obj_t* me)
{
	me->x = 99;

	BRIDGE_SECOND_PILE_INIT(usb_to_wifi_bridge,me);
}


void usb_comm_process(usb_obj_t* me)   
{ 
	printf(" usb_comm_process %d \n", me->x); 
	        
	//wifi_obj_t* reach = CONTAINER_OF(me->usb_to_wifi, wifi_obj_t, wifi_to_usb);
	 
	wifi_obj_t* reach = BRIDGE_GOTO_CROSS(usb_to_wifi_bridge, me, wifi_obj_t);

	if (reach) {
      printf(" usb is reacing wifi %d \n", reach->y); 
	}
	

	 
}