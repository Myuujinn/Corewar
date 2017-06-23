/*
** zjmp.c for  in /home/maxime/Repo/CPE_2016_corewar/corewar/src/instruction/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Wed Mar 29 21:42:57 2017 Maxime Desforest
** Last update Thu Mar 30 19:05:04 2017 Maxime Desforest
*/
#include "corewar.h"
#include "op.h"

int zjmp(t_game *game, int i)
{
  short jump;

  jump = 0;
  if (game->heads[i].carry == 0)
    {
      game->heads[i].pos = (game->heads[i].pos + 3) % MEM_SIZE;
      return 0;
    }
  jump = (game->mem[(game->heads[i].pos + 1) % MEM_SIZE] << 8) & 0xFFFF;
  jump = (jump + (((game->mem[(game->heads[i].pos + 2) % MEM_SIZE]) & 0xFF)));
  game->heads[i].pos = (game->heads[i].pos + (jump % IDX_MOD)) % MEM_SIZE;
  game->heads[i].delay = 20;
  return 0;
}
