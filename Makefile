##
## Makefile for Makefile in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_matchstick
## 
## Made by Kevin Bidet
## Login   <bibibrutal@epitech.net>
## 
## Started on  Mon Feb 20 11:18:40 2017 Kevin Bidet
## Last update Sat Feb 25 13:43:40 2017 Kevin Bidet
##

CC	=	gcc -g3

CFLAGS +=	-W -Wall -Wextra

NAME	=	matchstick

LIB	=	-L. -lperso

RM	=	rm -rf

SRC	=	set_struct_var.c	\
		board_manipulation.c	\
		error.c			\
		error_user_input.c	\
		display_board.c		\
		display_input.c		\
		game_step.c		\
		ia_input.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

go:		re
		$(RM) $(OBJ)
