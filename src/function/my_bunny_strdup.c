/*
** my_bunny_strdup.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Mon Jan 25 20:10:11 2016 Walter Bonetti
** Last update Sun Jan 31 09:18:17 2016 Michel Mancier
*/

#include "../../include/tekpaint.h"

char    *my_bunny_strdup(char *str)
{
  char  *dest;

  dest = (char *)bunny_malloc(sizeof(char) * my_strlen(str) + 1);
  if (dest == NULL)
    return (NULL);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
