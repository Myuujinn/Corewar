/*
** main.c for corewar in /home/victor/ASM/CPE_2016_corewar
**
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
**
** Started on  Wed Mar  8 18:40:32 2017 Victor LE DANTEC
** Last update Sun Apr  2 22:16:12 2017 Maxime Desforest
*/

#include "corewar.h"
#include "libmy.h"

int	main(int ac, char **av)
{
  t_game	game;

  help(av);
  game.mem = create_mem();
  init_function(&game);
  game.champ_nbr = count_champs(av);
  game.champs = op_malloc(sizeof(t_champ) * game.champ_nbr);
  init_champs(&game, av);
  show_mem(game.mem);
  vm_loop(&game);
  my_free(game.heads);
  game.heads = NULL;
  op_free();

  return (0);
  ac++;
}
