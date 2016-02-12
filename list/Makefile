##
## Makefile for  in /home/bonett_w/Documents/rendu/PSU_2015_minishell1/list/
##
## Made by Walter Bonetti
## Login   <bonett_w@epitech.eu>
##
## Started on  Thu Jan 21 16:34:27 2016 Walter Bonetti
## Last update Thu Jan 21 20:22:31 2016 Walter Bonetti
##

CC	=	gcc

FLAG	=	-W -Wall -Werror -Wextra -I./include

SRC	=	init.c \
		remove.c \
		node.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	liblist.a

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@echo -n "Cleaning .o files..."
	@$(RM) $(OBJ)
	@echo -e "\t [\e[32mOk !\e[39m]"

fclean:	clean
	@echo -n "Cleaning executable..."
	@$(RM) $(NAME)
	@echo -e "\t [\e[32m0k !\e[39m]"

re: fclean all

.c.o: %.c
	@$(CC) -c $< -o $@ $(FLAG) && \
	echo -e "\e[32m[OK]\e[39m" $< || \
	echo -e "\e[33m[ERR]\e[39m" $<

.PHONY: re fclean clean all
