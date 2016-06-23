/*
** pose_pixel.c for gfx_tekdesktop in /home/juquet_q/rendu/infographie/gfx_tekdesktop/lib
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Mon Apr 11 15:22:41 2016 juquet_q
** Last update Wed Jun 15 16:46:26 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void			pose_pixel(t_data *data,
				   t_bunny_position *pos,
				   int size)
{
  t_bunny_position	position;

  position.y = pos->y;
  while (position.y < pos->y + size)
    {
      position.x = pos->x;
      while (position.x < pos->x + size)
	{
	  tekpixel(data->pix, &position, WHITE);
	  position.x++;
	}
      position.y++;
    }
}
