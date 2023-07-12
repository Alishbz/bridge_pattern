#pragma once
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
#ifndef BRIDGE_PATTERN_TEST_H
#define BRIDGE_PATTERN_TEST_H
#ifdef __cplusplus
extern "C"
{
#endif
	 
	#include "stdio.h"
	#include "stdint.h"
	#include "stdlib.h"
	#include "string.h"
	#include <math.h>
	#include <time.h>
	#include <ctype.h>
	#include "math.h"
	#include <stdint.h>
	#include <stdarg.h>
	#include <stddef.h>
 
	#define CONTAINER_OF(ptr, type, member)    ((type *)((uintptr_t)(ptr) - offsetof(type, member)))



	/**************************************************************************************/

	typedef struct{
		int x;
		int y;
	}point_2d;
	 
	typedef struct test_object_ops {
		void (*position)(const test_object_ops **ops , point_2d *out);
	}test_object_ops; 
	 
	static inline void test_object_position(const test_object_ops** ops, point_2d* out)
	{
		(*ops)->position(ops, out);
	}

	/*****************************************************************************************/

	typedef struct {
		point_2d pos;
	    test_object_ops* ops;
	}server_circle;
	 
	
	 
	/*****************************************************************************************/


	typedef struct {
		point_2d pos;
	    test_object_ops* ops;
	}server_square;


	/*****************************************************************************************/


	typedef struct draw_ops {
		void (*draw)( draw_ops** ops );
	}draw_ops;
  
	static inline void draw_draw( draw_ops** ops)
	{
		(*ops)->draw(ops );
	}

	/*****************************************************************************************/


	typedef struct {
		test_object_ops** server_object;
		draw_ops*  drawable;
	}client_circle;

	 
	 
	/*****************************************************************************************/

	typedef struct {
		test_object_ops** server_object;
		draw_ops* drawable;
	}client_square;

	/*****************************************************************************************/










	void bridge_pattern_test_run(void);






#ifdef __cplusplus
}
#endif
#endif