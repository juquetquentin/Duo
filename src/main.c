/*
** main.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Mon Jun 13 15:30:06 2016 juquet_q
** Last update Wed Jun 15 10:57:05 2016 juquet_q
*/

#include <time.h>
#include <lapin.h>
#include "duo.h"

static  t_bunny_response  clavier(t_bunny_event_state s,
                                  t_bunny_keysym k,
				  void *d)
{
  (void)d;
  if (k == BKS_ESCAPE && s)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static  t_bunny_response  souris(const t_bunny_position *pos,
				 void *d)
{
  (void)d;
  (void)pos;
  return (GO_ON);
}

t_bunny_response	mainloop(t_data *data)
{
  background(data->pix, BLACK);
  tekcircle(data, data->grey);
  tekcircle_full(data, data->red);
  tekcircle_full(data, data->blue);
  move(bunny_get_keyboard(), data);
  print_brick(data, data->brick);
  brick_fall(data->brick);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &data->pos);
  bunny_display(data->win);
  return (GO_ON);
}

int		main()
{
  t_data	data;

  srand(time(NULL));
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, WIN_NAME)) == NULL)
    return (EXIT_FAILURE);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (EXIT_FAILURE);
  data.pos.x = 0;
  data.pos.y = 0;
  set_circle(&data);
  set_brick(&data, data.brick);
  bunny_set_key_response(clavier);
  bunny_set_move_response(souris);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(data.win, FPS, &data);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_stop(data.win);
  return (EXIT_SUCCESS);
}
