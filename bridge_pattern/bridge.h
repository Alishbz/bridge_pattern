/****************************************************************************************
* ALI SAHBAZ
*
*
* ASZ / ASOS Framework
*
* Date          : 05.07.2023
* By            : Ali Þahbaz
* e-mail        : ali_sahbaz@outlook.com
*/
#pragma once
#ifndef BRIDGE_H
#define BRIDGE_H
#ifdef __cplusplus
extern "C"
{
#endif
    #include <stddef.h>
	#include <stdio.h> 
	#include <stdlib.h> 
	#include <stdint.h>

	typedef struct {
		char way; // can be add queue
	}bridge_pure_t;

	/*** client can access to server, server not access to client ***/
	typedef bridge_pure_t*  bridge_server_way;
	typedef bridge_pure_t** bridge_client_way;
	 
	typedef enum {
		BRIDGE_FIRST_PILE,
		BRIDGE_SECOND_PILE
	}bridge_type_t;


    #define BRIDGE_OBJ_CREATE(bridge_shared_object_number)             \
	        bridge_pure_t shared_area_a_##bridge_shared_object_number; \
            bridge_pure_t shared_area_b_##bridge_shared_object_number

	#define BRIDGE_FIRST_PILE_CREATE(bridge_object_number)    \
	        bridge_server_way tx_way_##bridge_object_number;  \
            bridge_client_way rx_way_##bridge_object_number;  \
	        bridge_type_t     bridge_pile##bridge_object_number
	 
	#define BRIDGE_SECOND_PILE_CREATE(bridge_object_number)    \
	        bridge_server_way rx_way_##bridge_object_number;   \
            bridge_client_way tx_way_##bridge_object_number;   \
            bridge_type_t     bridge_pile##bridge_object_number
	 
    #define BRIDGE_FIRST_PILE_INIT(bridge_object_number , my_obj_pointer)    \
	        my_obj_pointer->tx_way_##bridge_object_number = NULL;  \
            my_obj_pointer->rx_way_##bridge_object_number = NULL;  \
            my_obj_pointer->bridge_pile##bridge_object_number = BRIDGE_FIRST_PILE

	#define BRIDGE_SECOND_PILE_INIT(bridge_object_number , my_obj_pointer)    \
	        my_obj_pointer->tx_way_##bridge_object_number = NULL;  \
            my_obj_pointer->rx_way_##bridge_object_number = NULL;  \
			my_obj_pointer->bridge_pile##bridge_object_number = BRIDGE_SECOND_PILE


	#define BRIDGE_CONNECTION_ASSIGN(bridge_shared_object_number ,bridge_object_number  , first_obj , second_obj)             \
	{\
		    first_obj.tx_way_##bridge_object_number  = &shared_area_a_##bridge_shared_object_number;     \
			second_obj.rx_way_##bridge_object_number = &shared_area_b_##bridge_shared_object_number;     \
			first_obj.rx_way_##bridge_object_number =  &second_obj.rx_way_##bridge_object_number; \
			second_obj.tx_way_##bridge_object_number = &first_obj.tx_way_##bridge_object_number;  \
	}while (0)


	/** 
	* "BRIDGE_GOTO_CROSS"
	* 
	Fcross Pointer Logic Creator : Ali Sahbaz 
	ref:
		CONTAINER_OF(ptr, type, member)    ((type *)((uintptr_t)(ptr) - offsetof(type, member)))

		Can be manage bridge piles and it will find its own way, then reach the cross object
	**/
	#define BRIDGE_GOTO_CROSS(bridge_object_number , my_obj_pointer , cross_obj_type)  \
			((cross_obj_type*)(((uintptr_t)(my_obj_pointer->rx_way_##bridge_object_number) - offsetof(cross_obj_type, rx_way_##bridge_object_number))* (my_obj_pointer->bridge_pile##bridge_object_number == BRIDGE_FIRST_PILE) +\
			((uintptr_t)(my_obj_pointer->tx_way_##bridge_object_number) - offsetof(cross_obj_type, tx_way_##bridge_object_number)) * (my_obj_pointer->bridge_pile##bridge_object_number == BRIDGE_SECOND_PILE)));
 

#ifdef __cplusplus
}
#endif
#endif