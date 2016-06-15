/*
** move.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 09:29:15 2016 juquet_q
** Last update Wed Jun 15 10:58:19 2016 juquet_q
*/

#include <lapin.h>
#include <math.h>
#include "duo.h"

void			brick_fall(t_rectangle brick[NB_BRICK])
{
  (void)brick;
}

void			move(const bool *key, t_data *data)
{
  double		angle;
  double		rayon;

  rayon = data->grey.rayon;
  if (key[BKS_RIGHT] == true)
    {
      data->angle += 2 * (M_PI * 2 / 180);
      data->red.center.x = data->grey.center.x + rayon * cos(data->angle);
      data->red.center.y = data->grey.center.y + rayon * sin(data->angle);
      angle = data->angle + M_PI;
      data->blue.center.x = data->grey.center.x + rayon * cos((angle));
      data->blue.center.y = data->grey.center.y + rayon * sin((angle));
    }
  if (key[BKS_LEFT] == true)
    {
      data->angle -= 2 * (M_PI * 2 / 180);
      data->red.center.x = data->grey.center.x + rayon * cos(data->angle);
      data->red.center.y = data->grey.center.y + rayon * sin(data->angle);
      angle = data->angle + M_PI;
      data->blue.center.x = data->grey.center.x + rayon * cos((angle));
      data->blue.center.y = data->grey.center.y + rayon * sin((angle));
    }
}
