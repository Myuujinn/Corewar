/*
** live.c for  in /home/maxime/Repo/CPE_2016_corewar/corewar/src/instruction/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Mon Mar 27 17:12:27 2017 Maxime Desforest
** Last update Thu Mar 30 20:09:49 2017 Maxime Desforest
*/

#include "corewar.h"
#include "libmy.h"

int     lookaway(t_game *game, int i)
{
        return ((game->mem[i % MEM_SIZE] << 24) |
         (game->mem[(i + 1) % MEM_SIZE] << 16) |
         (game->mem[(i + 2) % MEM_SIZE] << 8) |
         game->mem[(i + 3) % MEM_SIZE]);
}

int	what_champ(int champ, t_game *game)
{
  int   i;

  i = 0;
  while (i < game->champ_nbr)
    {
      if (game->champs[i].nbr == champ && game->champs[i].isalive != -1)
        return (i);
      i++;
    }
  return (-1);
}

int     set_live(t_champ *champ)
{
  champ->isalive = 1;
  my_putstr("player ");
  my_put_nbr(champ->nbr);
  my_putstr("(");
  my_putstr(champ->name);
  my_putstr(") is alive\n");
  return (0);
}

int     live(t_game *game, int i)
{
  int	champ;

  game->heads[i].pos++;
  champ = lookaway(game, game->heads[i].pos);
  champ = what_champ(champ, game);
  if (champ == -1)
  {
    game->heads[i].pos = game->heads[i].pos + 4;
    game->heads[i].delay = 10;
    return (0);
   }
  set_live(&game->champs[champ]);
  game->nbr_live++;
  game->heads[i].pos = game->heads[i].pos + 4;
  game->heads[i].delay = 10;
  return (0);
}
