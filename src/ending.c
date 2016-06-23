/*
** ending.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 16:39:36 2016 juquet_q
** Last update Wed Jun 15 17:42:20 2016 juquet_q
*/

#include <string.h>
#include <lapin.h>
#include <unistd.h>
#include "duo.h"

t_bunny_response	ending_screen(t_data *data)
{
  t_bunny_position	pos;

  background(data->pix, BLACK);
  pos.x = WIDTH / 2 - ((strlen(END) * 7 * SIZE_END) / 2);
  pos.y = HEIGHT / 2 - YOLO;
  aff_txt(data, END, &pos, SIZE_END);
  return (GO_ON);
}
