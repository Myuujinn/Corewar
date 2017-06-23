##
## Makefile for libmy-reboot in /home/myujinn/Libmy-reboot
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Sun Jan 15 11:23:36 2017 Victor LE DANTEC
## Last update Sun Mar 26 22:39:14 2017 Victor LE DANTEC
##

NAME	=	libmy.a

SRC	=	my_calloc.c		\
		my_getnbr.c		\
		my_malloc.c		\
		my_memset.c		\
		my_memcpy.c		\
		my_power.c		\
		my_put_adress.c		\
		my_putchar.c		\
		my_put_nbr_base.c	\
		my_put_nbr.c		\
		my_putstr.c		\
		my_show_wordtab.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_strlen.c		\
		my_strsep.c		\
		my_strstr.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_swap.c		\
		my_tabdup.c		\
		op_malloc.c		\
		op_free.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

CC	=	gcc

CFLAGS	+=	-Wall -Wextra -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
