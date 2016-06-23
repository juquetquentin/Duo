/*
** print_char.c for gfx_tekdesktop in /home/juquet_q/rendu/infographie/gfx_tekdesktop/lib
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Mon Apr 11 15:21:49 2016 juquet_q
** Last update Wed Jun 15 16:48:33 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void			print_char(char c, t_bunny_position *position,
				   t_data *data, int size)
{
  int			x;
  int			y;
  t_color		col;
  t_bunny_position	pos;

  pos.y = position->y;
  y = 0;
  while (y < 7)
    {
      pos.x = position->x;
      x = c * 5;
      while (x < (c + 1) * 5)
	{
	  col = get_pixel_txt(data->font, x, y);
	  if (col.argb[ALPHA_CMP] == 255)
	    pose_pixel(data, &pos, size);
	  x++;
	  pos.x += size;
	}
      pos.y += size;
      y++;
    }
}
