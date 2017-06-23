/*
** or.c for Projects in /home/Projects/Projects/or.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Fri Mar 31 00:00:43 2017 Moana DUMORA
** Last update Fri Mar 31 00:00:43 2017 Moana DUMORA
*/

#include "corewar.h"

int	direct_or(t_game *game, int i)
{
  int	res;

  res = (game->mem[game->heads[i].pos % MEM_SIZE] << 24) |
	(game->mem[(game->heads[i].pos + 1) % MEM_SIZE] << 16) |
	(game->mem[(game->heads[i].pos + 2) % MEM_SIZE] << 8) |
	game->mem[(game->heads[i].pos + 3) % MEM_SIZE];
  game->heads[i].pos += 4;
  return (res);
}

int	indirect_or(t_game *game, int i, int pos)
{
  int	indir, res;

  indir = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
	  game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  res = (game->mem[(pos + indir) % MEM_SIZE] << 24) |
	(game->mem[(pos + (1 + indir) % IDX_MOD) % MEM_SIZE] << 16) |
	(game->mem[(pos + (2 + indir) % IDX_MOD) % MEM_SIZE] << 8) |
	game->mem[(pos + (3 + indir) % IDX_MOD) % MEM_SIZE];
  game->heads[i].pos += 2;
  return (res);
}

int	register_or(t_game *game, int i)
{
  int	tmp;

  tmp = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  return (game->champs[game->heads[i].who].reg[tmp]);
}

int	for_the_norm(char cb[9], t_game *game, int i, int save)
{
  int	first;

  if (cb[0] == '0' && cb[1] == '1')
    first = register_or(game, i);
  else if (cb[0] == '1' && cb[1] == '0')
    first = direct_or(game, i);
  else if (cb[0] == '1' && cb[1] == '1')
    first = indirect_or(game, i, save);
  else
    return (-1000);
  return (first);
}

int	cw_or(t_game *game, int i)
{
  int	first, sec, save, ind_reg;
  char 	cb[9];

  save = game->heads[i].pos;
  byte_to_array(cb, game->mem[(game->heads[i].pos + 1) % MEM_SIZE]);
  game->heads[i].pos += 2;
  if ((first = for_the_norm(cb, game, i, save)) == -1000)
    return (-1);
  if (cb[2] == '0' && cb[3] == '1')
    sec = register_or(game, i);
  else if (cb[2] == '1' && cb[3] == '0')
    sec = direct_or(game, i);
  else if (cb[2] == '1' && cb[3] == '1')
    sec = indirect_or(game, i, save);
  else
    return (-1);
  ind_reg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  game->champs[game->heads[i].who].reg[ind_reg] = first | sec;
  game->heads[i].carry =
   (game->champs[game->heads[i].who].reg[ind_reg] == 0 ? 1 : 0);
  game->heads[i].delay = 6;
  return (0);
}