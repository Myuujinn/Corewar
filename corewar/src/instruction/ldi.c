/*
** ldi.c for Projects in /home/Projects/Projects/ldi.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Fri Mar 31 15:11:37 2017 Moana DUMORA
** Last update Fri Mar 31 15:11:37 2017 Moana DUMORA
*/

#include "corewar.h"

int	indirect_ldi(t_game *game, int save, int i)
{
  int	indir;

  indir = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
   game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  game->heads[i].pos += 2;
  return ((game->mem[(save + (indir % IDX_MOD)) % MEM_SIZE] << 8) |
	  game->mem[(save + (1 + indir % IDX_MOD)) % MEM_SIZE]);
}

int	direct_ldi(t_game *game, int i)
{
  int	tmp;

  tmp = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
   game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  game->heads[i].pos += 2;
  return (tmp);
}

int	get_result(t_game *game, int save, int s)
{
  s = (s < 0) ? -s : s;
  return ((game->mem[(save + (s % IDX_MOD)) % MEM_SIZE] << 24) |
	  (game->mem[(save + (1 + s % IDX_MOD)) % MEM_SIZE] << 16) |
	  (game->mem[(save + (2 + s % IDX_MOD)) % MEM_SIZE] << 8) |
	  game->mem[(save + (3 + s % IDX_MOD)) % MEM_SIZE]);
}

int	line_winner(char cb[9], t_game *game, int i, int save)
{
  int	first;

  if (cb[0] == '1' && cb[1] == '1')
    first = indirect_ldi(game, save, i);
  else if (cb[0] == '1' && cb[1] == '0')
    first = direct_ldi(game, i);
  else if (cb[0] == '0' && cb[1] == '1')
    first = game->champs[game->heads[i].who]
     .reg[(int)game->mem[game->heads[i].pos++ % MEM_SIZE]];
  else
    return (-1000);
  return (first);
}

int	ldi(t_game *game, int i)
{
  char 	cb[9];
  int	save, first, second, reg;

  save = game->heads[i].pos;
  byte_to_array(cb, game->mem[(game->heads[i].pos + 1) % MEM_SIZE]);
  game->heads[i].pos += 2;
  if ((first = line_winner(cb, game, i, save)) == -1000)
    return (-1);
  if (cb[2] == '1' && cb[3] == '0')
    second = direct_ldi(game, i);
  else if (cb[2] == '0' && cb[3] == '1')
    second = game->champs[game->heads[i].who]
     .reg[(int)game->mem[game->heads[i].pos++ % MEM_SIZE]];
  else
    return (-1);
  reg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  game->champs[game->heads[i].who].reg[reg] =
   get_result(game, save, first + second);
  game->heads[i].delay = 25;
  return (0);
}