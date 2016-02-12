/*
** tekpaint.h for  in /home/bonett_w/Documents/rendu/gfx_tekpaint/include/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Tue Jan 26 15:53:37 2016 Walter Bonetti
** Last update Sun Jan 31 22:55:58 2016 Matthias RIGAUD
*/

#ifndef TEKPAINT_H_
# define TEKPAINT_H_

# include <unistd.h>
# include <alloca.h>
# include <math.h>
# include <lapin.h>
# include <stdlib.h>
# include "../LibMcCloud/include/foxtek.h"
# include "../LibMcCloud/include/foxwindow.h"
# include "../LibMcCloud/include/my.h"
# include "../list/include/list.h"

/*
** Splashscreen (Because it's awesome !)
*/

void	splashscreen(t_bunny_window *win);

int	match(char *s1, char *s2);

/*
** Event Gestion
** Callback Function
*/

void	set_max_heap_size(size_t);

t_bunny_response	callback_move(const t_bunny_position	*relative,
				      void			*_data);
t_bunny_response	callback_click(t_bunny_event_state	state,
				       t_bunny_mousebutton	button,
				       void			*_data);

/*
** Fox_Bursh
** Brushing / Drawing
*/

typedef struct		s_brush
{
  t_bunny_position	size;
  t_bunny_pixelarray	*brush;
  unsigned int		color;
  void			(*pf_draw)(t_bunny_pixelarray *layer,
			 t_window_mouse *mouse, struct s_brush *brush);
}			t_brush;

/*
** Default Structur for tekpaint
*/

typedef struct		s_layer
{
  t_bunny_pixelarray	*pix;
  char			*name;
  char			visible;
  char			is_modified;
}			t_layer;

/*
** structure line
*/

typedef struct		s_ext
{
  t_bunny_position	fist;
  t_bunny_position	second;
}			t_ext;

/*
** Structure tekpain
** status (0 = isn't modified / 1 = modified)
*/

typedef struct		s_tekpain
{
  t_list		layers;
  t_list		mouse_history;
  t_node		*current_layer;
  t_bunny_position	workzone;
  short			type;
  short			capture;
  short			one_click;
  unsigned int		current_color;
  unsigned int		tmp_color[2];
  short			menu_toggle;
  unsigned char		alpha;
  t_bunny_position	menu_pos;
  int			status;
  int			is_start;
  int			forme;
  t_bunny_pixelarray	*menu;
  char			*path;
  int			size;
  int			line_begin;
  t_ext			ext_line;
  t_bunny_position	f_pos;
  int			opt;
  int			is_drug;
  t_bunny_music		*smoke_weed_every_day;
  unsigned char		trans_lvl;
}			t_tekpain;

typedef struct  s_layheader
{
  unsigned int  size;
  char          name[100];
}               t_layheader;

/*
** Tekpaint Data
** The easy way
*/

int	one_click(t_window_mouse *mouse, t_tekpain *paint);

t_tekpain	*tekpain_new(t_bunny_position workzone);
void		tekpaint_close(t_tekpain *paint);

/*
** Fill color function
**
*/

void	drug(t_tekpain	*paint);

void            square(t_window_mouse           *mouse,
                       t_bunny_pixelarray       *pix,
                       t_tekpain                *paint);

void    fox_draw_filled_cricle(t_bunny_pixelarray       *pix,
                               t_bunny_position         *pos,
                               unsigned int             color,
                               int                      radius);

void    line(t_bunny_pixelarray *pix,
             t_ext              *ext,
             unsigned int	color,
             int                size);

void    linesq(t_bunny_pixelarray	*pix,
	       t_ext			*ext,
	       t_color			*color,
	       t_bunny_position		*size);

void		my_putline(t_bunny_pixelarray   *pix,
			   t_window_mouse       *mouse,
			   t_tekpain            *paint);

void		my_putrectangle(t_bunny_pixelarray   *pix,
				t_window_mouse       *mouse,
				t_tekpain            *paint);

void		elipse(t_bunny_pixelarray   *pix,
		       t_window_mouse       *mouse,
		       t_tekpain            *paint);

void		fruit_salad(t_bunny_pixelarray	*pix,
			    t_color		*color,
			    float		portion);

void		blurp(t_bunny_pixelarray *pix, int intensit);

void		dark_pixelarray(t_bunny_pixelarray *pix);

void		kinder_bueno_mode(t_bunny_pixelarray *pix);

void		set_background(t_bunny_pixelarray *pix);

void		rackaille(t_bunny_pixelarray		*pix,
			  const t_bunny_position	*pos,
			  t_color			*color,
			  int				size);

void		paint_pincile_draw(t_window_mouse 	*mouse,
				   t_layer		*cur,
				   t_tekpain		*paint);

void	paint_bucket(t_window_mouse 	*mouse,
		     t_layer		*cur,
		     t_tekpain		*paint);

void		pf_remove(t_node 		*node);

int		layer_init_list(t_tekpain 	*paint);

int		layer_add(t_tekpain 		*paint,
			  t_layer 		*layer);

t_layer		*layer_new(char 		*name,
			   t_bunny_pixelarray 	*pix,
			   int			clean);

int		next_layer(t_tekpain *paint);
int		back_layer(t_tekpain *paint);

void		blih_layers(t_bunny_pixelarray 	*buffer,
			    t_list 		*layers);

void		paint_blit(t_bunny_pixelarray 	*alpha,
			   t_bunny_pixelarray 	*layer);

int		toggle_layer(t_tekpain *paint);

int	fill_flood(t_bunny_pixelarray *pix,
		   t_bunny_position *pos,
		   const t_color *color,
		   int *statu);

void	paint_gomme(t_window_mouse 	*mouse,
		    t_layer		*cur,
		    t_tekpain		*paint);

void	paint_pipette(t_window_mouse 	*mouse,
		      t_layer		*cur,
		      t_tekpain		*paint);

/*
** list && fonct for fill_flood
*/

typedef struct          s_pxlst
{
  t_bunny_position      pos;
  struct s_pxlst	*next;
}                       t_pxlst;

int     nw_pxlst(t_pxlst **old,
                 t_bunny_position *pos);

t_pxlst         *dl_elem_pxlst(t_pxlst **old);

/*
** Rewriting Mallocation on basic function
**
*/

char    *my_bunny_strdup(char *str);
void		*my_memcpy(void *dest, void *src, size_t size);
void		*my_memset(void *dest, char c, size_t size);

/*
** Mouse History
** Temps / Drawing
*/

void			mouse_history_remove(t_node 		*node);
void			mouse_history_init(t_tekpain 		*paint);

t_bunny_position	*mouse_history_add(const t_bunny_position *mouse_pos);

/*
** Fox Format
** Gestion
*/

# define GXY fox_getpixelxy
# define H pix->clipable.clip_height
# define W pix->clipable.clip_width
# define HB pix->clipable.buffer.height
# define WB pix->clipable.buffer.width

# pragma pack(push, 1)

typedef	struct		s_format_fox_header
{
  unsigned int		count;
  t_bunny_position	workzone;
  char			offset[255];
}			t_format_fox_header;

# pragma pack(pop)

int	export_format_fox(int fd, t_tekpain *paint);
int	import_format_fox(int fd, t_tekpain *paint);
void	export_format_bmp(t_fox_window *window, t_tekpain *paint);

typedef struct		s_nodestack
{
  t_bunny_position 	pos;
  struct s_nodestack 	*next;
}			t_nodestack;

void			stack_push(t_nodestack **top, int x, int y);
t_bunny_position	stack_pop(t_nodestack **);
int			stack_empty(t_nodestack *);
t_nodestack		*get_node(int x, int y);

void	paint_save(t_tekpain *paint);

/*
** Button
*/

typedef struct		s_btn
{
  t_bunny_pixelarray	*pic;
  t_bunny_position	pos;
  void			*fonc;
}			t_btn;

int	tools_action(t_tekpain *paint, t_layer *cur, t_fox_window *window);
void	toggle_menu(int	keysym, int state, t_tekpain *paint);
void	update_create_format(t_fox_window *win, t_tekpain *paint);

void	paint_line(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint);

void	paint_rect(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint);

void	paint_elips(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint);

void		paint_spray(t_window_mouse 	*mouse,
			    t_layer		*cur,
			    t_tekpain		*paint);

void	paint_negatif(t_window_mouse 	*mouse,
		      t_layer		*cur,
		      t_tekpain		*paint);

void	paint_kinder(t_window_mouse 	*mouse,
		     t_layer		*cur,
		     t_tekpain		*paint);
void	paint_blur(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint);
void	paint_gris(t_window_mouse 	*mouse,
		   t_layer		*cur,
		   t_tekpain		*paint);
void	paint_salade(t_window_mouse 	*mouse,
		     t_layer		*cur,
		     t_tekpain		*paint);

void		paint_random(t_window_mouse 	*mouse,
			     t_layer		*cur,
			     t_tekpain		*paint);

int	paint_size_mode(t_fox_window	*win,
			t_tekpain	*paint,
			int 		add_value);

void	color_swich(t_tekpain *paint);
void	tekpaint_menu_draw_default(t_tekpain *paint);

/*
** Gestion du menu
** Gestion des buttons
** Gestion des champs
*/

typedef struct		s_button
{
  t_bunny_position	pos;
  t_bunny_position	size;
  short			type;
}			t_button;

t_button		set_btn(short				type,
				t_bunny_position		btn_pos,
				t_bunny_position		btn_size);
t_bunny_position	setpos(int x, int y);

int			in_box_button(t_bunny_position		ms_realative,
				      t_button			btn);

int	menu_btn(t_fox_window *win, t_tekpain *paint);
void	menu_block_save(t_fox_window *win, t_tekpain *paint);
void	menu_block_outils(t_fox_window *win, t_tekpain *paint);
void	menu_block_palette(t_fox_window *win, t_tekpain *paint);
void	menu_block_settings(t_fox_window *win, t_tekpain *paint);
void	menu_block_plus(t_fox_window *win, t_tekpain *paint);

/*
** gest pixelarray
*/

t_bunny_pixelarray	*open_pixelarray();

/*
** Define de la mort qui tue
*/

# define	VA(x)	((x < 0) ? (-(x)) : (x))
# define	CAR(x)	((x) * (x))
# define	WW	1024
# define	HW	768
# define	GREY	RGBA_C(128, 128, 128, 255)
# define	WBLUE	RGBA_C(0, 110, 255, 255)
/*
** Gestion des calques nouvelles functions
*/

int	load_bmp_layer(t_tekpain *paint);
int	add_layer(t_tekpain *paint);
int	remove_layer(t_tekpain *paint);
int	layers_dislpay_menu(t_tekpain *paint);

#endif /* !TEKPAINT_H_ */
