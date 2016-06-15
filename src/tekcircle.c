/*
** tekcircle.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 08:51:47 2016 juquet_q
** Last update Wed Jun 15 09:25:03 2016 juquet_q
*/

#include <lapin.h>
#include <math.h>
#include <stdio.h>
#include "duo.h"

void	tekcircle_full(t_data *data, t_circle circle)
{
  double	save;

  save = circle.rayon;
  while (circle.rayon > 0)
    {
      tekcircle(data, circle);
      circle.rayon--;
    }
  circle.rayon = save;
}

void			tekcircle(t_data *data, t_circle circle)
{
  double		angle_rad;
  int			angle_deg;
  t_bunny_position	pos;

  angle_deg = 0;
  while (angle_deg <= 360)
    {
      angle_rad = (angle_deg * M_PI) / 180;
      pos.x = circle.center.x + circle.rayon * cos(angle_rad);
      pos.y = circle.center.y + circle.rayon * sin(angle_rad);
      tekpixel(data->pix, &pos, circle.color.full);
      angle_deg++;
    }
}
