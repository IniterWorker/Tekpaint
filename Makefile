##
## Makefile for  in /home/bonett_w/Documents/rendu/gfx_tekpaint
##
## Made by Walter Bonetti
## Login   <bonett_w@epitech.net>
##
## Started on  Sat Jan  2 18:51:45 2016 Walter Bonetti
## Last update Sun Jan 31 20:51:38 2016 Walter Bonetti
##

CC	=	gcc

RM	=	rm -f

NAME	=	tekpaint

SRC	=	src/main.c \
		src/draw.c \
		src/mouse_draw.c \
		src/list_history.c \
		src/init_tekpain.c \
		src/fill_flood.c \
		src/pix_list.c \
		src/function/set_background.c \
		src/function/my_bunny_strdup.c \
		src/function/my_memcpy.c \
		src/layer/blit.c \
		src/layer/action_layer.c \
		src/layer/layer_load_bmp.c \
		src/layer/init_layer.c \
		src/export/save.c \
		src/export/bmp.c \
		src/button.c \
		src/negative.c \
		src/toggle.c \
		src/kinder_bueno.c \
		src/blurp.c \
		src/menu.c \
		src/fruit_salad.c \
		src/rackaille.c \
		src/function_draw.c \
		src/function_draw_plus.c \
		src/line.c \
		src/menu_block.c \
		src/menu_block_plus.c \
		src/layer/show_layers.c \
		src/safe_size.c \
		src/btn.c \
		src/click.c \
		src/linesq.c \
		src/putline.c \
		src/square.c \
		src/putrectangle.c \
		src/elipse.c \
		src/match.c \
		src/splashscreen.c \
		src/drug.c

OBJ	=	$(SRC:.c=.o)

FLAG	=	-ansi -pedantic -std=c99 \
		-W -Wall -Werror -I./LibMcCloud/include -Iinclude

LIB	=	-L./LibMcCloud/lib -lmccloud \
		-L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-L./lib \
		-lm \
		-lmy \
		-L./list -llist

all: $(NAME)

$(NAME): $(OBJ)
	@cd list && make
	@cd LibMcCloud && make
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@echo -e "\e[32mAll done !\e[39m"

clean:
	@echo -n "Cleaning .o files..."
	@$(RM) $(OBJ)
	@echo -e "\t [\e[32mOk !\e[39m]"
	@cd list && make clean
	@cd LibMcCloud && make clean
	@echo -e "\e[32mAll done !\e[39m"

fclean:	clean
	@echo -n "Cleaning executable..."
	@$(RM) $(NAME)
	@echo -e "\t [\e[32m0k !\e[39m]"

reall:
	@cd list && make re
	@cd LibMcCloud && make re

re: reall fclean all

.c.o: %.c
	@echo -e "\e[32m->\e[39m" $<
	@$(CC) -c $< -o $@ $(FLAG)

.PHONY: all re fclean clean
