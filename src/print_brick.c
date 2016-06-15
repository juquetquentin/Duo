/*
** print_brick.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Wed Jun 15 10:53:08 2016 juquet_q
** Last update Wed Jun 15 10:55:15 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void	print_brick(t_data *data, t_rectangle brick[8])
{
  int	i;

  i = 0;
  while (i < NB_BRICK)
    tekrect(data, brick[i++]);
}
