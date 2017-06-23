/*
** sti.c for Projects in /home/Projects/Projects/sti.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Tue Mar 28 17:56:32 2017 Moana DUMORA
** Last update Sun Apr  2 22:12:24 2017 Maxime Desforest
*/

#include <stdio.h>
#include "op.h"
#include "corewar.h"

void	write_byte(t_game *game, char nbr[4], int place)
{
  place = (place < 0) ? -place : place;
  game->mem[place % MEM_SIZE] = nbr[0];
  game->mem[(place + 1) % MEM_SIZE] = nbr[1];
  game->mem[(place + 2) % MEM_SIZE] = nbr[2];
  game->mem[(place + 3) % MEM_SIZE] = nbr[3];
}

int	direct_sti(t_game *game, int i)
{
  int	tmp;

  tmp = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
   game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  game->heads[i].pos += 2;
  return (tmp);
}

int	indirect_sti(t_game *game, int save, int i)
{
  int	tmp;

  tmp = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
   game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  game->heads[i].pos += 2;
  tmp = (tmp < 0) ? -tmp : tmp;
  return ((game->mem[(save + (tmp % IDX_MOD)) % MEM_SIZE] << 24) |
   (game->mem[(save + (1 + tmp % IDX_MOD)) % MEM_SIZE] << 16) |
   (game->mem[(save + (2 + tmp % IDX_MOD)) % MEM_SIZE] << 8) |
   game->mem[(save + (3 + tmp % IDX_MOD)) % MEM_SIZE]);
}

int	norm_seeker(char cb[9], t_game *game, int i, int save)
{
  int	first;

  if (cb[2] == '0' && cb[3] == '1')
    first = game->champs[game->heads[i].who].
     reg[game->mem[game->heads[i].pos++] - 1];
  else if (cb[2] == '1' && cb[3] == '1')
    first = indirect_sti(game, save, i);
  else if (cb[2] == '1' && cb[3] == '0')
    first = direct_sti(game, i);
  else
    return (-1000);
  return (first);
}

int	sti(t_game *game, int i)
{
  char 	cb[9], nbr[4];
  int	save, indreg, first, sec;

  save = game->heads[i].pos;
  byte_to_array(cb, game->mem[(game->heads[i].pos + 1) % MEM_SIZE]);
  game->heads[i].pos += 2;
  indreg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  if ((first = norm_seeker(cb, game, i, save)) == -1000)
    return (-1);
  if (cb[4] == '0' && cb[5] == '1')
    sec = game->champs[game->heads[i].who].
     reg[game->mem[game->heads[i].pos++] - 1];
  else if (cb[4] == '1' && cb[5] == '0')
    sec = direct_sti(game, i);
  else
    return (-1);
  int_in_bytes(nbr, game->champs[game->heads[i].who].reg[indreg]);
  write_byte(game, nbr, first + sec + save);
  game->heads[i].delay = 25;
  return (0);
}
