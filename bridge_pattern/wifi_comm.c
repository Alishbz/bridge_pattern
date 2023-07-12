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
#include "wifi_comm.h"

#include "usb_comm.h" // for reach

void wifi_comm_create(wifi_obj_t* me  )
{
	me->y = 11; 

	BRIDGE_FIRST_PILE_INIT(usb_to_wifi_bridge, me);
	 
}

void wifi_comm_process(wifi_obj_t* me)
{ 
	printf(" wifi_comm_process %d \n" , me->y ); 

	usb_obj_t* reach = BRIDGE_GOTO_CROSS(usb_to_wifi_bridge, me , usb_obj_t);
	
	if (reach) {
		printf(" wifi is reacing usb %d \n", reach->x); 
	}
}