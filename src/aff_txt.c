/*
** main.c for main in /home/juquet_q/rendu/Projets_perso/lecteur_musique
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Fri Jan 29 16:20:41 2016 juquet_q
** Last update Wed Jun 15 17:41:25 2016 juquet_q
*/

#include <lapin.h>
#include "duo.h"

void			aff_txt(t_data *data, char *str,
				t_bunny_position *pos, int size)
{
  int			i;
  t_bunny_position	position;

  if (str == NULL)
    return ;
  position.x = pos->x;
  position.y = pos->y;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 0 && 0)
	print_char('?', &position, data, size);
      else if (str[i] >= 32 && str[i] <= 126)
	{
	  print_char(str[i], &position, data, size);
	  position.x += 6 * size;
	}
      i++;
    }
}
