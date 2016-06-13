/*
** background.c for Duo in /home/juquet_q/Hub/Duo
** 
** Made by juquet_q
** Login   <juquet_q@epitech.net>
** 
** Started on  Mon Jun 13 16:11:14 2016 juquet_q
** Last update Mon Jun 13 16:13:25 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void			background(t_bunny_pixelarray *pix, unsigned int color)
{
  t_bunny_position	pos;
  
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  tekpixel(pix, &pos, color);
	  pos.x++;
	}
      pos.y++;
    }
}
