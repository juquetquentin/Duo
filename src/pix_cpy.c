/*
** pix_cpy.c for gfx_tekdesktop in /home/antoine/Documents/gfx_tekdesktop/lib
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 13 20:13:15 2016 antoine
** Last update Wed Jun 15 16:46:12 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void			pix_cpy(t_bunny_pixelarray	*dest,
				t_bunny_pixelarray	*src,
				int	x_start, int y_start)
{
  int			x;
  int			y;
  t_bunny_position	pos;
  t_color		color;

  y = 0;
  while (y < src->clipable.buffer.height)
    {
      x = 0;
      while (x < src->clipable.buffer.width)
	{
	  pos.x = x + x_start;
	  pos.y = y + y_start;
	  color = get_pixel_txt(src, x, y);
	  if (color.argb[ALPHA_CMP] == 255)
	    tekpixel(dest, &pos, color.full);
	  x++;
	}
      y++;
    }
}
