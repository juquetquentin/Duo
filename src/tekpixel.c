/*
** tekpixel.c for Duo in /home/juquet_q/Hub/Duo
** 
** Made by juquet_q
** Login   <juquet_q@epitech.net>
** 
** Started on  Mon Jun 13 16:13:36 2016 juquet_q
** Last update Mon Jun 13 16:14:52 2016 juquet_q
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, unsigned int col)
{
  if (pos->x >= 0 && pos->x <= pix->clipable.clip_width
      && pos->y >= 0 && pos->y <= pix->clipable.clip_height)
    ((t_color*)pix->pixels)[pos->y * pix->clipable.clip_width + pos->x].full = col;
}
