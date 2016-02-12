/*
** foxtek.h for FoxTek in /home/mei/Perso/LibMcCloud/include/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Mon Dec 21 23:59:43 2015 Michel Mancier
** Last update Sat Jan 30 22:28:29 2016 Matthias RIGAUD
*/

#ifndef FOXTEK_H_
# define FOXTEK_H_

# include <lapin.h>

/*
** ****************************************
** Macros plutôt pratiques               **
** ****************************************
** ABS : Renvoie la absolue du nombre envoyé en paramètre
** SGN : Renvoie le signe du nombre (0, 1 ou -1)
** RGBA_C : Crée un unsigned avec les valeurs RGBA passées
** RGBA_G : Renvoie une couleur donnée en niveau de gris
** MIN : renvoie le min
** MAX : renvoie le max
** HB : hauteur du pixelarray pix
** WB : largeur du pixelarray pix
*/

# define ABS(n)			((n < 0) ? (-n) : (n))
# define SGN(n)			((n < 0) ? -1 : ((n > 0) ? 1 : 0))
# define RGBA_C(r, g, b, a)	((a << 24) | (b << 16) | (g << 8) | r)
# define RGBA_G(r, g, b, a)	((r + g + b) / 3)
# define MIN(a, b) 		(((a) < (b)) ? (a) : (b))
# define MAX(a, b) 		(((a) < (b)) ? (a) : (b))
# define HB			pix->clipable.buffer.height
# define WB			pix->clipable.buffer.width
# define maskR(x) (x & 0x00FF0000)
# define maskG(x) (x & 0x0000FF00)
# define maskB(x) (x & 0x000000FF)

/*
** ****************************************
** Define sur les fonctions simples      **
** ****************************************
** getxy = fox_calc_pos
*/

# define getxy			fox_calc_pos

/*
** ****************************************
** Structures !                          **
** ****************************************
** Fox_Headerfile : Contient le header d'un fichier lu
** Fox_BmpHeader : Contient tout le header d'un fichier Bitmap
** Fox_Bkgd : Contient 4 unsigned char ?
*/

# pragma pack(push, 1)

typedef	struct	s_fox_headerfile
{
  char		filetype[2];
  unsigned int	filesize;
  short		reserved[2];
  unsigned int	dataoffset;
}		t_fox_headerfile;

# pragma pack(pop)

# pragma pack(push, 1)

typedef	struct			s_fox_bmpheader
{
  struct s_fox_headerfile	fileheader;
  unsigned int			headersize;
  int				width;
  int				height;
  short				planes;
  short				bitsperpixels;
  unsigned int			compression;
  unsigned int			bitmapsize;
  int				horizontalres;
  int				verticalres;
  unsigned int			numcolors;
  unsigned int			impcolors;
}				t_fox_bmpheader;

typedef	struct	s_fox_bkgd
{
  unsigned char	blue;
  unsigned char	green;
  unsigned char	red;
  unsigned char	reserved;
}		t_fox_bgr;

# pragma pack(pop)

typedef struct	s_fox_line
{
  t_bunny_position	d;
  t_bunny_position	sens;
  t_bunny_position	i;
  t_bunny_position	p;
}		t_fox_line;

/*
** *****************************************
** Functions utilitaires                  **
** *****************************************
*/

int	fox_calc_pos(int x, int y, const t_bunny_pixelarray *pix);
t_color	fox_calc_color(t_color *newc, t_color *oldc);

t_bunny_pixelarray	*fox_new_pixelarray(unsigned int	width,
					    unsigned int	height,
					    unsigned int	color);

void	fox_blit_center(t_bunny_window				*win,
			t_bunny_pixelarray			*pix);

void	fox_blit_upleft(t_bunny_window				*win,
			t_bunny_pixelarray			*pix);

void	fox_blit_upright(t_bunny_window				*win,
			 t_bunny_pixelarray			*pix);

void	fox_blit_downleft(t_bunny_window			*win,
			  t_bunny_pixelarray			*pix);

void	fox_blit_dowright(t_bunny_window			*win,
			  t_bunny_pixelarray			*pix);

void	fox_blit_xy(t_bunny_window				*win,
		    t_bunny_pixelarray				*pix,
		    int x, int y);

/*
** *****************************************
** Functions de pixels                    **
** *****************************************
*/

void	fox_setpixel(t_bunny_pixelarray				*pix,
		     t_bunny_position				*pos,
		     t_color					*color);

void	fox_tekpixel(t_bunny_pixelarray				*pix,
		     t_bunny_position				*pos,
		     unsigned int				color);

t_color	fox_getpixel(t_bunny_pixelarray 			*pix,
		     t_bunny_position				*pos);

unsigned int	fox_getpixelxy(t_bunny_pixelarray *pix,
			       int		x,
			       int		y);

/*
** ****************************************
** Fonctions de tracé                    **
** ****************************************
** Fox Draw Forme : Cette fonction doit prendre une structure
** t_bunny_position contenant nb éléments. On tracera une forme
** composée de tous ces traits !
*/

void	fox_draw_line(t_bunny_pixelarray	*pix,
		      t_bunny_position		*pos,
		      unsigned int		color);

void	fox_draw_rectangle_fill(t_bunny_pixelarray		*pix,
				t_bunny_position		pos,
				t_bunny_position		size,
				t_color				color);

void	fox_draw_circle(t_bunny_pixelarray			*pix,
			t_bunny_position			*center,
			unsigned int				radius,
			t_color					*color);

void	fox_draw_circle_faster(t_bunny_pixelarray		*pix,
			       t_bunny_position			*center,
			       unsigned int			radius,
			       t_color				*color);

void	fox_draw_polygon(t_bunny_pixelarray			*pix,
			 t_bunny_position			*pos,
			 unsigned int				nb,
			 t_color				*color);

void	fox_fill_array(t_bunny_pixelarray			*pix,
		       t_color					*color);

/*
** ****************************************
** Fonctions de load                     **
** ****************************************
** Fox_Load_Bmp : Charge un fichier bmp dans une PixelArray
*/

t_fox_bmpheader		fox_getbmpheader(int fd);
void			fox_dispbmpheader(t_fox_bmpheader *b);
void			fox_bmptopixel(int			fd,
				       t_bunny_pixelarray	*pix,
				       t_fox_bmpheader		*bitmap);
t_bunny_pixelarray	*fox_load_bmp(const char		*path);

/*
** ****************************************
** Fonctions de save                     **
** ****************************************
** Fox_Load_Bmp : Sauvegarde une Pixelarray dans un fichier bmp
*/

void	fox_save_bmp(const char *path, const t_bunny_pixelarray *img);

/*
** ****************************************
** Fonctions de transformation           **
** ****************************************
*/

t_color	fox_color_converter(unsigned int			color);

void	fox_mod_grey(t_bunny_pixelarray				*pix);

void	fox_mod_stretch(t_bunny_pixelarray			*pix,
			t_bunny_pixelarray			*ori);

/*
** ****************************************
** Fonctions de transformation couleurs  **
** ****************************************
*/

float	fox_lerping(float v0, float v1, float t);

t_color	fox_lerp(unsigned int	to,
		 unsigned int	color,
		 float		amount);

/*
** ****************************************
** Fonctions de son et musique           **
** ****************************************
*/

# define ERR_NOLOAD_MUSIC (-1)

int	fox_load_music(t_bunny_music *music, char *filepath, int volume);
int	fox_load_effect(t_bunny_effect *effect, char *filepath, int volume);

#endif /* !FOXTEK_H_ */
