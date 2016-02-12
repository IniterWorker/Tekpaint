/*
** blurp.c for tekpaint in /home/rigaud_b/rendu/gfx_tekpaint/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.net>
**
** Started on  Tue Jan 26 22:34:03 2016 Matthias RIGAUD
** Last update Thu Jan 28 13:47:20 2016 Matthias RIGAUD
*/

#include <tekpaint.h>

int		moy(t_bunny_pixelarray *pix, int i, int j, int v)
{
  t_color	*pixels;
  int		coef;
  int		som;

  pixels = pix->pixels;
  som = pixels[getxy(i, j, pix)].argb[v];
  coef = 1;
  if (i - 1 >= 0 && j - 1 >= 0 && ++coef)
    som += pixels[getxy(i - 1, j - 1, pix)].argb[v];
  if (i - 1 >= 0 && ++coef)
    som += pixels[getxy(i - 1, j, pix)].argb[v];
  if (i - 1 >= 0 && j + 1 < HB && ++coef)
    som += pixels[getxy(i - 1, j + 1, pix)].argb[v];
  if (j - 1 >= 0 && ++coef)
    som += pixels[getxy(i, j - 1, pix)].argb[v];
  if (j + 1 < HB && ++coef)
    som += pixels[getxy(i, j + 1, pix)].argb[v];
  if (i + 1 < WB && j - 1 >= 0 && ++coef)
    som += pixels[getxy(i + 1, j - 1, pix)].argb[v];
  if (i + 1 < WB && ++coef)
    som += pixels[getxy(i + 1, j, pix)].argb[v];
  if (i + 1 < WB && j + 1 < HB && ++coef)
    som += pixels[getxy(i + 1, j + 1, pix)].argb[v];
  return (som / coef);
}

void		blurp(t_bunny_pixelarray *pix, int intensit)
{
  t_color	*pixels;
  t_color	*cpy;
  int		i;
  int		j;

  pixels = pix->pixels;
  cpy = alloca(HB * WB * sizeof(t_color));
  while (intensit--)
    {
      i = -1;
      while (++i < WB)
	{
	  j = -1;
	  while (++j < HB)
	    cpy[getxy(i, j, pix)].full = RGBA_C(moy(pix, i, j, 0),
						moy(pix, i, j, 1),
						moy(pix, i, j, 2),
						moy(pix, i, j, 3));
	}
      i = -1;
      while (++i < WB * HB)
	pixels[i].full = cpy[i].full;
    }
}
