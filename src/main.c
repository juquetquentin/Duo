/*
** main.c for Duo in /home/juquet_q/Hub/Duo/src
** 
** Made by juquet_q
** Login   <juquet_q@epitech.net>
** 
** Started on  Mon Jun 13 15:30:06 2016 juquet_q
** Last update Mon Jun 13 16:25:42 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

t_bunny_response	mainloop(t_data *data)
{
  background(data->pix, BLACK);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &data->pos);
  bunny_display(data->win);
  return (GO_ON);
}

int		main()
{
  t_data	data;

  if ((data.win = bunny_start(WIDTH, HEIGHT, false, WIN_NAME)) == NULL)
    return (EXIT_FAILURE);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (EXIT_FAILURE);
  data.pos.x = 0;
  data.pos.y = 0;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(data.win, FPS, &data);
  return (EXIT_SUCCESS);
}