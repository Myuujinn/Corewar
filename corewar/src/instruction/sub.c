/*
** sub.c for Projects in /home/Projects/Projects/sub.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Fri Mar 31 01:22:39 2017 Moana DUMORA
** Last update Fri Mar 31 01:22:39 2017 Moana DUMORA
*/

#include "corewar.h"

int	sub(t_game *game, int i)
{
  char 	cb[9];
  int	first, sec, indreg, tmp;

  byte_to_array(cb, game->mem[(game->heads[i].pos + 1) % MEM_SIZE]);
  if (cb[0] != '0' || cb[1] != '1' || cb[2] != '0' ||
      cb[3] != '1' || cb[4] != '0' || cb[5] != '1')
    return (-1);
  game->heads[i].pos += 2;
  tmp = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  first = game->champs[game->heads[i].who].reg[tmp];
  tmp = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  sec = game->champs[game->heads[i].who].reg[tmp];
  indreg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  game->champs[game->heads[i].who].reg[indreg] = first - sec;
  game->heads[i].delay = 10;
  return (0);
}