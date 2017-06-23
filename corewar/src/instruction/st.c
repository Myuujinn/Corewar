/*
** st.c for Projects in /home/Projects/Projects/st.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Wed Mar 29 21:32:22 2017 Prenom Nom
** Last update Wed Mar 29 21:32:22 2017 Prenom Nom
*/

#include "op.h"
#include "corewar.h"

void	registre_st(t_game *game, int i, int reg)
{
  int	tmp;

  tmp = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  game->champs[game->heads[i].who].reg[tmp] =
   game->champs[game->heads[i].who].reg[reg];
  if (game->champs[game->heads[i].who].reg[reg] == 0)
    game->heads[i].carry = 1;
}

void	indirect_ld(t_game *game, int i, int nbr, int save)
{
  int 	tmp;
  char 	byt[4];

  tmp = (game->mem[game->heads[i].pos % MEM_SIZE] << 8) |
   game->mem[(game->heads[i].pos + 1) % MEM_SIZE];
  game->heads[i].pos += 2;
  tmp = (tmp < 0) ? -tmp : tmp;
  int_in_bytes(byt, nbr);
  game->mem[(save + tmp % IDX_MOD) % MEM_SIZE] = byt[0];
  game->mem[(save + (1 + tmp) % IDX_MOD) % MEM_SIZE] = byt[1];
  game->mem[(save + (2 + tmp) % IDX_MOD) % MEM_SIZE] = byt[2];
  game->mem[(save + (3 + tmp) % IDX_MOD) % MEM_SIZE] = byt[3];
  if (nbr == 1)
    game->heads[i].carry = 1;
}

int	st(t_game *game, int i)
{
  int	reg, save;
  char	cb[9];

  save = game->heads[i].pos;
  byte_to_array(cb, game->mem[(game->heads[i].pos + 1) % MEM_SIZE]);
  game->heads[i].pos += 2;
  if (cb[0] == '0' && cb[1] == '1')
    reg = game->mem[game->heads[i].pos++ % MEM_SIZE] - 1;
  else
    return (-1);
  if (cb[2] == '0' && cb[3] == '1')
    registre_st(game, i, reg);
  else if (cb[2] == '1' && cb[3] == '1')
    indirect_ld(game, i, game->champs[game->heads[i].who].reg[reg], save);
  else
    return (-1);
  game->heads[i].delay = 5;
  return (0);
}