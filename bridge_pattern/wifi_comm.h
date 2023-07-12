 
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
#ifndef WIFI_COMM_H
#define WIFI_COMM_H
#ifdef __cplusplus
extern "C"
{
#endif

	#include "bridge.h"

	typedef struct {
		 
		int y;
		
		BRIDGE_FIRST_PILE_CREATE( usb_to_wifi_bridge );

	}wifi_obj_t;

	void wifi_comm_create(wifi_obj_t * me );
	void wifi_comm_process(wifi_obj_t* me); 

#ifdef __cplusplus
}
#endif
#endif