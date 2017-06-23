##
## Makefile for get_next_line in /home/victor/CPE/CPE_2016_matchstick
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Mon Feb 13 17:20:32 2017 Victor LE DANTEC
## Last update Mon Mar 13 00:01:07 2017 Victor LE DANTEC
##

NAME	=	libgnl.a

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CC	=	gcc

CFLAGS	+=	-Wall -Werror -Wextra -pedantic -I../my -L../my -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
