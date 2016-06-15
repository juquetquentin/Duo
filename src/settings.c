/*
** settings.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 03:38:04 2016 juquet_q
** Last update Wed Jun 15 10:54:43 2016 juquet_q
*/

#include "duo.h"

void			set_brick(t_data *data, t_rectangle brick[NB_BRICK])
{
  int			i;
  t_bunny_position	pos;
  double		rayon;

  rayon = data->grey.rayon;
  pos.x = data->grey.center.x - (rayon / 2) + ((rand() % 2) * rayon);
  pos.y = 0;
  i = 0;
  while (i < NB_BRICK)
    {
      brick[i].pos.x = pos.x;
      brick[i].pos.y = pos.y;
      brick[i].height = BRICK_HEIGHT;
      brick[i].width = BRICK_WIDTH;
      brick[i].color.full = WHITE;
      pos.x = data->grey.center.x - (rayon / 2) + ((rand() % 2) * rayon);
      pos.y -= rayon;
      i++;
    }
}

void	set_circle(t_data *data)
{
  data->grey.center.x = WIDTH / 2;
  data->grey.center.y = HEIGHT / 2;
  data->grey.color.full = 0xFFFFFF;
  data->grey.rayon = 100;
  data->grey.full = false;
  data->blue.center.x = data->grey.center.x - (data->grey.rayon * 3 / 4);
  data->blue.center.y = data->grey.center.y - (data->grey.rayon * 3 / 4);
  data->blue.color.full = BLUE;
  data->blue.rayon = data->grey.rayon / 4;
  data->blue.full = true;
  data->red.center.x = data->grey.center.x + (data->grey.rayon * 3 / 4);
  data->red.center.y = data->grey.center.y + (data->grey.rayon * 3 / 4);
  data->red.color.full = RED;
  data->red.rayon = data->grey.rayon / 4;
  data->red.full = true;
  data->angle = M_PI * 1 / 4;
}
