##
## Makefile for corewar in /home/victor/ASM/CPE_2016_corewar
## 
## Made by Victor LE DANTEC
## Login   <victor.le-dantec@epitech.eu>
## 
## Started on  Wed Mar  8 18:27:42 2017 Victor LE DANTEC
## Last update Sun Mar 12 23:57:23 2017 Victor LE DANTEC
##

NAME	=	corewar

all:		$(NAME)

$(NAME):
		$(MAKE) -C ./lib/my
		$(MAKE) -C ./lib/gnl
		$(MAKE) -C ./asm
		$(MAKE) -C ./corewar

clean:
		$(MAKE) -C ./asm clean
		$(MAKE) -C ./corewar clean
		$(MAKE) -C ./lib/my clean
		$(MAKE) -C ./lib/gnl clean

fclean:		clean
		$(MAKE) -C ./asm fclean
		$(MAKE) -C ./corewar fclean
		$(MAKE) -C ./lib/my fclean
		$(MAKE) -C ./lib/gnl fclean

re:		fclean all

.PHONY:		all corewar asm clean fclean re
