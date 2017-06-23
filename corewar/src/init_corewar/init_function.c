/*
** init_function.c for  in /home/maxime/Repo/CPE_2016_corewar/corewar/src/init_corewar/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Tue Mar 28 17:31:43 2017 Maxime Desforest
** Last update Thu Mar 30 20:19:06 2017 Maxime Desforest
*/

#include "corewar.h"

void init_function(t_game *game)
{
  game->instruction[0] = live;
  game->instruction[1] = ld;
  game->instruction[2] = st;
  game->instruction[3] = add;
  game->instruction[4] = sub;
  game->instruction[5] = cw_and;
  game->instruction[6] = cw_or;
  game->instruction[7] = cw_xor;
  game->instruction[8] = zjmp;
  game->instruction[9] = ldi;
  game->instruction[10] = sti;
  game->instruction[11] = forkvm;
  game->instruction[15] = aff;
}
