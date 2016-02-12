/*
** my_memcpy.c for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/src/function/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Jan 26 14:46:46 2016 Walter Bonetti
** Last update Tue Jan 26 14:50:37 2016 Walter Bonetti
*/

#include <stdlib.h>

void		*my_memcpy(void *dest, void *src, size_t size)
{
  size_t	i;
  char		*d;
  char		*s;

  d = dest;
  s = src;
  i = 0;
  while (i < size)
    {
      d[i] = s[i];
      i++;
    }
  return (dest);
}

void		*my_memset(void *dest, char c, size_t size)
{
  size_t	i;
  char		*d;

  d = dest;
  i = 0;
  while (i < size)
    {
      d[i] = c;
      i++;
    }
  return (dest);
}
