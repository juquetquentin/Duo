/*
** tekrect.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 10:45:01 2016 juquet_q
** Last update Wed Jun 15 10:49:59 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void			tekrect(t_data *data, t_rectangle rect)
{
  t_bunny_position	pos;

  pos.y = rect.pos.y;
  while (pos.y < (rect.pos.y + rect.height))
    {
      pos.x = rect.pos.x;
      while (pos.x < (rect.pos.x + rect.width))
	{
	  tekpixel(data->pix, &pos, rect.color.full);
	  pos.x++;
	}
      pos.y++;
    }
}
