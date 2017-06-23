/*
** corewar.h for lol in /home/stickboy/Projects/CPE-Projects/CPE_2016_corewar
**
** Made by
** Login   <moana.dumora@epitech.eu>
**
** Started on  Mon Mar 27 15:22:33 2017
** Last update Mon Apr  3 00:44:06 2017 Victor LE DANTEC
*/

#pragma once

#include "op.h"
#include <unistd.h>

typedef	struct	s_heads
{
  int		pos;
  int		delay;
  int		who;
  int 		carry;
}		t_heads;

typedef struct  s_champ
{
  int           nbr;
  int		reg[REG_NUMBER];
  char          *name;
  int           amorce;
  int           isalive;
}               t_champ;

typedef struct  s_game
{
  int           champ_nbr;
  int           cycle;
  t_champ       *champs;
  char 		*mem;
  int 		nbr_heads;
  int		nbr_live;
  t_heads	*heads;
  int		show;
  int          (*instruction[16])(struct s_game *, int i);
}               t_game;

char 	*create_mem();
void	read_champ_prog(char *, t_game *, int);
void	show_mem(char *);
void	free_exit(int, char *);
void	init_champs(t_game *, char **);
int	vm_loop(t_game *);
void	init_heads(t_game *);
void	byte_to_array(char [], char);
void	int_in_bytes(char [], int);
int	check_win(t_game *, int);
int	sti(t_game *, int);
int	forkvm(t_game *, int);
int	indirect(t_game *, int);
int	direct(t_game *, int);
void    init_function(t_game *game);
int	ld(t_game *, int);
int     live(t_game *game, int i);
int     set_live(t_champ *champ);
int	st(t_game *, int);
int     zjmp(t_game *game, int i);
int	cw_and(t_game *, int);
int	cw_or(t_game *, int);
int	cw_xor(t_game *game, int);
int     add(t_game *, int);
int	sub(t_game *, int);
int	ldi(t_game *, int);
int	aff(t_game *, int);
void    *my_realloc(void *, size_t, size_t);
int	all_champions_dead(t_game *);
void	alive_champ_wins(t_game *);
void	help(char **);
int	count_champs(char **);
void	my_putnbr_base(int, char *);
void	helper();
