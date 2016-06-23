/*
** int_to_str.c for Duo in /home/juquet_q/Hub/Duo/src
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Thu Jun 23 10:23:45 2016 juquet_q
** Last update Thu Jun 23 10:48:52 2016 juquet_q
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int  my_intlen(int nbr)
{
  int       i;

  i = 1;
  while (nbr > 0)
  {
    i++;
    nbr /= 10;
  }
  return (i);
}

char    *int_to_str(int nbr)
{
  char  *str;
  int   len;

  len = my_intlen(nbr);
  if ((str = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  sprintf(str, "%d", nbr);
  str[len] = '\0';
  return (str);
}
