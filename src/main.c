/*
** main.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Mon Jun 13 15:30:06 2016 juquet_q
** Last update Thu Jun 23 10:54:19 2016 juquet_q
*/

#include <time.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <lapin.h>
#include "duo.h"

static  t_bunny_response	clavier(t_bunny_event_state s,
					t_bunny_keysym k,
					void *d)
{
  (void)d;
  if (k == BKS_ESCAPE && s)
    return (EXIT_ON_CROSS);
  return (GO_ON);
}

static  t_bunny_response	souris(const t_bunny_position *pos,
				       void *d)
{
  (void)d;
  (void)pos;
  return (GO_ON);
}

static	t_bunny_response	click(t_bunny_event_state s,
				      t_bunny_mouse_button b,
				      void *data)
{
  (void)s;
  (void)b;
  (void)data;
  return (GO_ON);
}

t_bunny_response	mainloop(t_data *data)
{
  int			retour;
  char			*str;
  t_bunny_position	pos;

  pos.x = pos.y = 0;
  str = int_to_str(data->score / 4);
  retour = GO_ON;
  if (bunny_get_keyboard()[BKS_SPACE] == true)
    data->pause = (data->pause == true) ? false : true;
  if (data->pause == false && data->end == false)
    {
      background(data->pix, BLACK);
      aff_txt(data, "Score :", &pos, 2);
      pos.x += 10 * (strlen(SCORE) + 1);
      aff_txt(data, str, &pos, 2);
      tekcircle(data, data->grey);
      tekcircle_full(data, data->red);
      tekcircle_full(data, data->blue);
      move(bunny_get_keyboard(), data);
      print_brick(data, data->brick);
      brick_fall(data, data->brick);
      if (collision(data->blue, data->brick) == true ||
	  collision(data->red, data->brick) == true)
	data->end = true;
    }
  else if (data->end == true)
    {
      background(data->pix, BLACK);
      retour = ending_screen(data);
    }
  bunny_blit(&data->win->buffer, &data->pix->clipable, &data->pos);
  bunny_display(data->win);
  return (retour);
}

int		main()
{
  t_data	data;

  srand(time(NULL));
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, WIN_NAME)) == NULL)
    return (EXIT_FAILURE);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (EXIT_FAILURE);
  if ((data.font = bunny_load_pixelarray(FONT_PATH)) == NULL)
    return (EXIT_FAILURE);
  data.pos.x = 0;
  data.pos.y = 0;
  data.pause = false;
  data.end = false;
  set_circle(&data);
  set_brick(&data, data.brick);
  bunny_set_key_response(clavier);
  bunny_set_click_response(click);
  bunny_set_move_response(souris);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_loop(data.win, FPS, &data);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_stop(data.win);
  return (EXIT_SUCCESS);
}
