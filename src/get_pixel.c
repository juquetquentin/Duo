/*
** get_pixel.c for gfx_tekpaint in /home/juquet_q/rendu/infographie/clone_tekpaint/gfx_tekpaint/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue Jan 26 18:42:55 2016 juquet_q
** Last update Wed Jun 15 16:46:03 2016 juquet_q
*/

#include <lapin.h>

t_color	get_pixel_txt(t_bunny_pixelarray	*pix,
		      int x, int y)
{
  return (((t_color*)pix->pixels)[y * pix->clipable.clip_width + x]);
}
