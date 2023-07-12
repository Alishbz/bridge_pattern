
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
#pragma once
#ifndef USB_COMM_H
#define USB_COMM_H
#ifdef __cplusplus
extern "C"
{
#endif


	#include "bridge.h" 

	typedef struct {
		 
		int x;
	
		BRIDGE_SECOND_PILE_CREATE( usb_to_wifi_bridge );

	}usb_obj_t;


	void usb_comm_create(usb_obj_t* me);
	void usb_comm_process(usb_obj_t* me);

#ifdef __cplusplus
}
#endif
#endif