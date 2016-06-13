/*
** duo.h for Duo in /home/juquet_q/Hub/Duo/include
** 
** Made by juquet_q
** Login   <juquet_q@epitech.net>
** 
** Started on  Mon Jun 13 15:22:24 2016 juquet_q
** Last update Mon Jun 13 16:24:41 2016 juquet_q
*/

#pragma once
#include <lapin.h>

#define WIN_NAME ("Duo")
#define WIDTH (1920)
#define HEIGHT (1080)
#define FPS (60)

typedef struct		s_circle
{
  t_bunny_position	center;
  t_color		color;
  double		angle;
  bool			full;
}			t_circle;

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_position	pos;
  t_circle		red;
  t_circle		blue;
  t_circle		grey;
}			t_data;


void	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, unsigned int color);
void	background(t_bunny_pixelarray *pix, unsigned int col);
