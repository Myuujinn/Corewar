/*
** fork.c for  in /home/maxime/Repo/CPE_2016_corewar/corewar/src/instruction/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Tue Mar 28 17:29:43 2017 Maxime Desforest
** Last update Sun Apr  2 20:59:41 2017 Maxime Desforest
*/

#include "corewar.h"
#include "libmy.h"

void	add_fork(t_game *game, int base, int poss, int i)
{

  game->heads = realloc(game->heads, sizeof(t_heads) * (game->nbr_heads + 1));
  if (game->heads == NULL)
        exit(84);
  game->nbr_heads += 1;
  game->heads[game->nbr_heads - 1].delay = 0;
  game->heads[game->nbr_heads - 1].carry = 0;
  game->heads[game->nbr_heads - 1].who = game->heads[i].who;
  game->heads[game->nbr_heads - 1].pos = (base - 1 + (poss % IDX_MOD));
}

int	forkvm(t_game *game, int i)
{
  int     poss;
  int     base;
  char    byte[2];

  game->heads[i].pos++;
  base = game->heads[i].pos;
  byte[0] = game->mem[(game->heads[i].pos) % MEM_SIZE];
  byte[1] = game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  poss = ((byte[0] << 8) | byte[1]) & 0xFFFF;
  game->heads[i].delay = 800;
  add_fork(game, base, poss, i);
  return (0);
}
