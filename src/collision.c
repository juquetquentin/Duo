/*
** collision.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 13:07:55 2016 juquet_q
** Last update Wed Jun 15 13:51:00 2016 juquet_q
*/

#include <unistd.h>
#include <math.h>
#include <lapin.h>
#include "duo.h"

static bool		impact(t_bunny_position pos, t_circle circle)
{
  double		distance;

  distance = sqrt(pow((pos.x - circle.center.x), 2) +
		  pow((pos.y - circle.center.y), 2));
  if (distance < circle.rayon)
    return (true);
  return (false);
}

bool			collision(t_circle circle, t_rectangle brick[NB_BRICK])
{
  int			i;
  t_bunny_position	pos;

  i = 0;
  while (i < NB_BRICK)
    {
      pos.y = brick[i].pos.y;
      while (pos.y < (brick[i].pos.y + brick[i].height))
	{
	  pos.x = brick[i].pos.x;
	  while (pos.x < (brick[i].pos.x + brick[i].width))
	    {
	      if (impact(pos, circle) == true)
		return (true);
	      pos.x++;
	    }
	  pos.y++;
	}
      i++;
    }
  return (false);
}
