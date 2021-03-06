/*
** move.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 09:29:15 2016 juquet_q
** Last update Thu Jun 23 11:11:35 2016 juquet_q
*/

#include <lapin.h>
#include <math.h>
#include "duo.h"

void			brick_fall(t_data *data, t_rectangle brick[NB_BRICK])
{
  int	    i;
  int     max_range;

  max_range = data->grey.center.y + data->grey.rayon + data->blue.rayon;
  i = 0;
  while (i < NB_BRICK)
    {
      if (brick[i].pos.y > HEIGHT)
	{
	  brick[i].pos.x = data->grey.center.x - (data->grey.rayon / 2) +
	      ((rand() % 2) * data->grey.rayon);
	  brick[i].pos.y = (i != 0) ? brick[(i - 1)].pos.y - (400) :
	      			      brick[(NB_BRICK - 1)].pos.y - (400);
	}
        else if (brick[i].pos.y > max_range && brick[i].pos.y < max_range + 10)
        {
            data->score++;
            if (data->score % (SCORE_COUNT * SCORE_COUNT) == 0)
              data->speed++;
        }
      brick[i].pos.y += 2 * data->speed;
      i++;
    }
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
