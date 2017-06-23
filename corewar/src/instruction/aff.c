/*
** aff.c for Projects in /home/Projects/Projects/aff.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Fri Mar 31 13:29:52 2017 Moana DUMORA
** Last update Fri Mar 31 13:29:52 2017 Moana DUMORA
*/

#include "corewar.h"
#include "libmy.h"

int	aff(t_game *game, int i)
{
  int	indreg;

  game->heads[i].pos++;
  if (game->mem[game->heads[i].pos++ % MEM_SIZE] != 64)
    return (-1);
  indreg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  my_putchar(game->champs[game->heads[i].who].reg[indreg] % 256);
  my_putchar('\n');
  game->heads[i].delay = 2;
  return (0);
}