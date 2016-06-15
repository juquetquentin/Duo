/*
** duo.h for Duo in /home/juquet_q/Hub/Duo/include
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Mon Jun 13 15:22:24 2016 juquet_q
** Last update Wed Jun 15 10:58:12 2016 juquet_q
*/

#pragma once
#include <lapin.h>

#define WIN_NAME ("Duo")
#define WIDTH (1920)
#define HEIGHT (1080)
#define BRICK_HEIGHT (40)
#define BRICK_WIDTH (BRICK_HEIGHT * 4)
#define FPS (60)
#define NB_BRICK (8)

typedef struct		s_circle
{
  t_bunny_position	center;
  t_color		color;
  double		rayon;
  bool			full;
}			t_circle;

typedef struct		s_rectangle
{
  t_bunny_position	pos;
  int			height;
  int			width;
  t_color		color;
}			t_rectangle;

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_position	pos;
  double		angle;
  t_rectangle		brick[8];
  t_circle		red;
  t_circle		blue;
  t_circle		grey;
}			t_data;

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color);
void	background(t_bunny_pixelarray *pix, unsigned int col);
void	set_circle(t_data *data);
void	tekcircle(t_data *data, t_circle circle);
void	tekcircle_full(t_data *data, t_circle circle);
void	move(const bool *key, t_data *data);
void	set_brick(t_data *data, t_rectangle brick[NB_BRICK]);
void	tekrect(t_data *data, t_rectangle rect);
void	print_brick(t_data *data, t_rectangle brick[NB_BRICK]);
void	brick_fall(t_rectangle brick[NB_BRICK]);
