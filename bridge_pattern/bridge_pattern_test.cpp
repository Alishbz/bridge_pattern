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
#include "bridge_pattern_test.h"

static test_object_ops  circle_ops;

static void server_circle_position(const test_object_ops** ops, point_2d* out)
{
	server_circle* self = CONTAINER_OF(ops, server_circle, ops);
	printf("server: get circle position : %d,%d\n", self->pos.x, self->pos.y);

}

static void server_circle_init(server_circle* self)
{
	memset(self, 0, sizeof(*self));
	circle_ops.position = server_circle_position;
	self->ops = &circle_ops;
}


/*****************************************************************************************/




static test_object_ops  square_ops;

static void server_square_position(const test_object_ops** ops, point_2d* out)
{
	server_square* self = CONTAINER_OF(ops, server_square, ops);   // bunlar adam da circle da kalmýþ ?
	printf("server: get square position : %d,%d\n", self->pos.x, self->pos.y);
}
 
static void server_square_init(server_square* self)
{
	memset(self, 0, sizeof(*self));
	square_ops.position = server_square_position;
	self->ops = &square_ops;
}

/*****************************************************************************************/




static draw_ops  circle_draw_ops;

static void client_circle_draw(draw_ops ** ops)
{
	client_circle* self = CONTAINER_OF(ops, client_circle, drawable);
	point_2d pos = { 0 };
	test_object_position((const test_object_ops**)self->server_object, &pos);
	printf("client: drawing circle position \n");
}

static void client_circle_init(client_circle* self, test_object_ops** server_obj)
{
	memset(self, 0, sizeof(*self));
	circle_draw_ops.draw = client_circle_draw;
	self->server_object = server_obj;
	self->drawable = &circle_draw_ops;
}


/*****************************************************************************************/


static draw_ops  square_draw_ops;

static void client_square_draw(draw_ops ** ops)
{
	client_square* self = CONTAINER_OF(ops, client_square, drawable);
	point_2d pos = { 0 };
	test_object_position((const test_object_ops**)self->server_object, &pos);
	printf("client: drawing square position\n");
}

static void client_square_init(client_square* self, test_object_ops** server_obj)
{
	memset(self, 0, sizeof(*self));
	square_draw_ops.draw = client_square_draw;
	self->server_object = server_obj;
	self->drawable = &square_draw_ops;
}









/***************************************************/

server_circle s_circle;
server_square s_square;
client_circle circle;
client_square square;

 
void bridge_pattern_test_run(void)
{
	server_circle_init(&s_circle);
	server_square_init(&s_square);


	client_circle_init(&circle , &s_circle.ops);
	client_square_init(&square, &s_square.ops);


	draw_draw(&circle.drawable);
	draw_draw(&square.drawable); 

	s_circle.pos.x = 6;
	s_circle.pos.y = 7; 
	draw_draw(&circle.drawable);
	draw_draw(&square.drawable);


	// client to server  !!
	server_circle *test = CONTAINER_OF(circle.server_object, server_circle, ops);
	test->pos.x = 87;
	test->pos.y = 89;
	draw_draw(&circle.drawable);
	draw_draw(&square.drawable);

  
}