##
## Makefile for corewar in /home/victor/ASM/CPE_2016_corewar
##
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
##
## Started on  Wed Mar  8 18:27:42 2017 Victor LE DANTEC
## Last update Mon Apr  3 00:42:03 2017 Victor LE DANTEC
##

NAME		=	corewar

SRC		=	src/main.c				\
			src/utils.c				\
			src/init_corewar/store_champ_info.c	\
			src/init_corewar/memory_utils.c		\
			src/parsing/parse_args.c		\
			src/run_corewar/loop.c			\
			src/instruction/convert_coding_byte.c	\
			src/instruction/sti.c			\
			src/init_corewar/init_function.c	\
			src/instruction/live.c			\
			src/instruction/fork.c			\
			src/instruction/zjmp.c			\
			src/run_corewar/checks.c		\
			src/instruction/ld.c			\
			src/instruction/st.c			\
			src/instruction/and.c			\
			src/instruction/or.c			\
			src/instruction/xor.c			\
			src/instruction/add.c			\
			src/instruction/sub.c			\
			src/instruction/ldi.c			\
			src/instruction/aff.c			\
			src/helper.c

OBJ		=	$(SRC:.c=.o)

INCLUDE		=	-I./include -I../lib/my

RM		=	rm -f

CFLAGS		+=	-Wall -Wextra -pedantic -L../lib/my -lmy $(INCLUDE)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)
			$(RM) vgcore.*

re:			fclean all

.PHONY:			all clean fclean re
