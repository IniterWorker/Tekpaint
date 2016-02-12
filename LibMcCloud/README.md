
La LibMcCloud !
=============

![DarkFox](http://image.noelshack.com/fichiers/2015/52/1450875392-fox2.png)

#### La lib avec des vrais morceaux de skill dedans !

## Contenu de la LibMcCloud

Pour plus d'informations sur chaque fonction, n'hésitez pas à lire le header !

### Macros

> - ABS(n) : Renvoie la valeur absolue de n
> - SGN(n) : Renvoie le signe de n (0, 1 ou -1)
> - RGBA_C(r, g, b, a) : Renvoie un Unsigned int de la couleur voulue
> - RGBA_G(r, g, b, a) : Renvoie un niveau de gris unsigned int correspondant

### Window Framework

> - fox_window_new : Renvoie un nouveau OBJ _t_fox_window_
> - fox_window_delete : Supprime un OBJ _t_fox_window_
> - fox_window_set_loop : Setter function loop
> - fox_window_set_key : Setter function key
> - fox_window_set_mouse : Setter function click / move
> - fox_window_starter : Custom starter

#### Basic example

Basic **example** to make a Window.

```c
int		main()
{
  t_fox_window	*win;

  win = FOX_DEFAULT_WINDOW(800, 600, "LibMcCloud");
  win->screen = bunny_new_pixelarray(800, 600);
  fox_window_set_loop(win, mainloop);
  fox_window_set_key(win, callback_key);
  fox_window_set_mouse(win, callback_click, callback_move);
  fox_window_starter(win);
  return (0);
}
```
Basic **callback** setting.
```c
t_bunny_response	callback_move(const t_bunny_position	*relative,
				                  void		          	*_data)
{
  t_fox_window		*window;

  window = _data;
  (void) window;
  my_printf(1, "[Mouse] pos .x: %d .y: %d\n", relative->x, relative->y);
  return (GO_ON);
}

```
```c
t_bunny_response	callback_click(t_bunny_event_state	state,
				                   t_bunny_mousebutton    button,
				                   void	               *_data)
{
  t_fox_window		*window;

  window = _data;
  (void) window;
  (void) button;
  (void) state;
  return (GO_ON);
}
```

```c
t_bunny_response	callback_key(t_bunny_event_state 	state,
				                 t_bunny_keysym 	 	keysym,
				                 void 		       	*_data)
{
  t_fox_window		*window;

  window = _data;
  (void) window;
  if (keysym == 36 && state)
    return (0);
  my_printf(1, "key : %d\n", keysym);
  return (GO_ON);
}
```
```c
t_bunny_response	mainloop(void *_data)
{
  t_fox_window		*window;

  window = _data;
  bunny_blit(&window->win->buffer,
             &window->screen->clipable,
             &window->zero_axis);
  bunny_display(window->win);
  return (GO_ON);
}
```

### Fonctions

#### Utilitaires

> - fox_calc_pos : Renvoie la position dans pix pour x et y
> - fox_calc_color : Calcule une couleur, alpha pris en compte (A tester)
> - fox_new_pixelarray : Permet de créer une pixelarray et de la remplir d'une couleur
> - fox_blit_center : Permet de centrer la pixelarray à blit automatiquement
> - fox_blit_upleft, fox_blit_upright, fox_blit_downleft, fox_blit_downright
> - fox_blit_xy : Permet de blit à la position souhaitée.

#### Pixels

> - fox_setpixel : Pose un pixel, simplement
> - fox_getpixel : Permet d'obtenir le t_color correspondant au pixel

#### Tracé

> - fox_draw_line : Dessine une ligne
> - fox_draw_rectangle : Dessine un rectangle
> - fox_draw_circle : Dessine un cercle
> - fox_draw_polygon : Dessine une forme à nb côtés. Non fonctionnelle pour le moment
> - fox_fill_array : Remplit l'array d'une couleur

#### Load

> - fox_load_bmp : Permet de charger un fichier BMP dans une Pixelarray

#### Transformation

> - fox_color_converter : Transforme un unsigned int en un t_color
> - fox_mod_stretch : Resize une image d'une pixelarray à une autre !

#### Transformation de Couleurs

> - fox_mod_grey : Applique un effet noir et blanc sur une pixelarray
> - fox_lerp : Permet d'interpoler deux couleurs et renvoie un t_color

#### Son et musique

> - fox_load_music : Charge une musique au volume souhaité (Loop)
> - fox_load_effect : Charge un effet/son au volume souhaité (Ne loop pas)

## Makefile

The **Makefile** configuration

> - The Makefile notify
> - The Makefile compile lib
> - The Makefile colored
> - Todo : **Rewrite** the Makefile

## Bonus d'autorisations

Un des principes simples de la LibLapin est que vous ne pouvez pas utiliser
la grand majorité des fonctions, à moins de les avoir recodé à l'avance.
Ainsi :

- fox_load_bmp : Donne accès à bunny_load_picture et bunny_load_pixelarray !

> Contributeurs :
>
> - mancie_m / MeixDev
> - bonett_w / IniterWorker
>
> Slack : https://brothersinarmsteam.slack.com/
