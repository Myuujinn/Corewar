/*
** ld.c for Projects in /home/Projects/Projects/ld.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Wed Mar 29 19:06:21 2017 Moana DUMORA
** Last update Wed Mar 29 20:24:50 2017 Maxime Desforest
*/

#include "corewar.h"

int     strtoint(t_game *game, int i, int j)
{
  int 	res;

  res = (game->mem[i % MEM_SIZE] << 24) |
   (game->mem[(i + 1) % MEM_SIZE] << 16) |
   (game->mem[(i + 2) % MEM_SIZE] << 8) |
   game->mem[(i + 3) % MEM_SIZE];
  game->heads[j].pos += 4;
   return (res);
}

int	ld(t_game *game, int i)
{
  char	cb[9];
  int	tmp, indir, ins_pos, ind_reg;

  ins_pos = game->heads[i].pos;
  byte_to_array(cb, game->mem[(game->heads[i].pos + 1) % MEM_SIZE]);
  game->heads[i].pos += 2;
  if (cb[0] == '1' && cb[1] == '0')
    tmp = strtoint(game, game->heads[i].pos, i);
  else if (cb[0] == '1' && cb[1] == '1')
    {
      indir = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
       game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
      game->heads[i].pos += 2;
      tmp = strtoint(game, ins_pos + indir, i);
    }
  else
    return (-1);
  ind_reg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  game->champs[game->heads[i].who].reg[ind_reg] = tmp;
  game->heads[i].carry = (tmp == 0) ? 1 : 0;
  game->heads[i].delay = 5;
  return (0);
}
