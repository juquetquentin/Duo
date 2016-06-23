/*
** duo.h for Duo in /home/juquet_q/Hub/Duo/include
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Mon Jun 13 15:22:24 2016 juquet_q
** Last update Thu Jun 23 10:51:24 2016 juquet_q
*/

#pragma once
#include <lapin.h>

#include <stdio.h>

#define WIN_NAME ("Duo")
#define WIDTH (1920)
#define SCORE ("Score : ")
#define SCORE_COUNT (4)
#define FONT_PATH ("./img/font.png")
#define YOLO (200)
#define HEIGHT (1080)
#define END ("Game Over")
#define SIZE_END (5)
#define BRICK_HEIGHT (50)
#define BRICK_WIDTH (BRICK_HEIGHT * 6)
#define FPS (30)
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
  t_bunny_pixelarray	*font;
  t_bunny_window	*win;
  t_bunny_position	pos;
  double		angle;
  int			score;
  int                   speed;
  bool			pause;
  bool			end;
  t_rectangle		brick[8];
  t_circle		red;
  t_circle		blue;
  t_circle		grey;
}			t_data;

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);
void			background(t_bunny_pixelarray *pix, unsigned int col);
void			set_circle(t_data *data);
void			tekcircle(t_data *data, t_circle circle);
void			tekcircle_full(t_data *data, t_circle circle);
void			move(const bool *key, t_data *data);
void			set_brick(t_data *data, t_rectangle brick[NB_BRICK]);
void			tekrect(t_data *data, t_rectangle rect);
void			print_brick(t_data *data, t_rectangle brick[NB_BRICK]);
void			brick_fall(t_data *data, t_rectangle brick[NB_BRICK]);
bool			collision(t_circle circle, t_rectangle[NB_BRICK]);
void			aff_txt(t_data *data, char *str,
				t_bunny_position *pos, int size);
t_color			get_pixel_txt(t_bunny_pixelarray *pix,
				      int x, int y);
t_bunny_response	ending_screen(t_data *data);
void			pose_pixel(t_data *data,
				   t_bunny_position *pos,
				   int size);
void			print_char(char c, t_bunny_position *position,
				   t_data *data, int size);
char                    *int_to_str(int nbr);
