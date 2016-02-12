##
## Makefile for Makefilz in /home/mei/Perso/LibMcCloud/
##
## Made by Michel Mancier
## Login   <mancie_m@epitech.eu>
##
## Started on  Tue Dec 22 15:37:06 2015 Michel Mancier
## Last update Wed Jan 27 05:56:08 2016 Nicolas Zimmermann
##

CC	=	gcc

RM	=	rm -f

MAIN	=	examples/main.c

FOX	=	fox/fox_calc_pos.c \
		fox/fox_calc_alpha.c \
		fox/fox_color_converter.c \
		fox/fox_load_bmp.c \
		fox/fox_draw_line.c \
		fox/fox_draw_circle.c \
		fox/fox_draw_rectangle.c \
		fox/fox_draw_polygon.c \
		fox/fox_setpixel.c \
		fox/fox_getpixel.c \
		fox/fox_fill_array.c \
		fox/fox_blit_center.c \
		fox/fox_blit_upleft.c \
		fox/fox_blit_upright.c \
		fox/fox_blit_downleft.c \
		fox/fox_blit_downright.c \
		fox/fox_blit_xy.c \
		fox/fox_mod_grey.c \
		fox/fox_mod_stretch.c \
		fox/fox_new_pixelarray.c \
		fox/fox_lerp.c \
		fox/fox_load_music.c \
		fox/fox_load_effect.c \
		fox/fox_tekpixel.c \
		fox/fox_load_bmp.c \
		fox/fox_save_bmp.c

WIN	=	fox/window/window.c \
		fox/window/setter.c \
		fox/window/init.c

SRC	= 	$(FOX)

SRC	+=	$(WIN)

NAME	=	mccloud

LIBNAME	=	lib/lib$(NAME).a

LIB	=	-L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-L./lib \
		-lm \
		-lmy

FLAG 	+=	-W -Wall -ansi -pedantic -std=c99
FLAG	+=	-I./include -I/home/${USER}/.froot/include/

OBJ 	=	$(SRC:.c=.o)

SRC	+=	$(MAIN)

OBJMAIN	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\e[32mAll done !\e[39m"
	@notify-send 'LibMcClound' \
	'Compilation finished correcty' \
	--icon=dialog-information
	@ar r $(LIBNAME) $(OBJ)
	@ranlib $(LIBNAME)

LIBMC	=	⁻l$(NAME)

ex:
	$(CC) $(FLAG) $(MAIN) $(LIB) -l$(NAME) -o $(NAME)

clean:
	@echo -n "Cleaning .o files..."
	@$(RM) $(OBJ)
	@echo -e "\t [\e[32mOk !\e[39m]"

fcleanlib:
	@echo -n "Cleaning lib..."
	@$(RM) $(LIBNAME)
	@echo -e "\t [\e[32m0k !\e[39m]"

fclean:		clean fcleanlib
	@echo -n "Cleaning executable..."
	@$(RM) $(NAME)
	@echo -e "\t [\e[32m0k !\e[39m]"

re: 	fclean all

.c.o: %.c
	@$(CC) -c $< -o $@ $(FLAG) && \
	echo -e "\e[32m[OK]\e[39m" $< || (\
	notify-send 'Compilation error' \
	$< \
	--icon=dialog-information && \
	 echo -e "\e[33m[ERR]\e[39m" $<)

.PHONY: all re fclean clean fcleanlib ex
