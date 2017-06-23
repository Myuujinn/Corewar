##
## Makefile for asm in /home/victor/ASM/CPE_2016_corewar
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Wed Mar  8 18:27:42 2017 Victor LE DANTEC
## Last update Thu Mar 30 20:41:29 2017 Victor LE DANTEC
##

NAME		=	asm

SRC		=	src/main.c			\
			src/error.c			\
			src/op.c			\
			src/compile_champion.c		\
			src/parse_header.c		\
			src/parser_utils.c		\
			src/big_endian_converter.c	\
			src/label.c			\
			src/char_in_string.c		\
			src/lexer.c			\
			src/tokenizer.c			\
			src/evaluator.c			\
			src/token_manipulation.c	\
			src/args_check.c		\
			src/write_instructions.c	\
			src/coding_byte.c		\
			src/write_args.c		\
			src/get_name.c

OBJ		=	$(SRC:.c=.o)

INCLUDE		=	-I./include -I../lib/my -I../lib/gnl

RM		=	rm -f

CC		=	gcc

LIBS		=	-L../lib/gnl -lgnl -L../lib/my -lmy

CFLAGS		+=	-Wall -Wextra -pedantic $(LIBS) $(INCLUDE)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
