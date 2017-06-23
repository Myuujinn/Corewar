/*
** loop.c for Projects in /home/Projects/Projects/loop.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Tue Mar 28 13:51:55 2017 Moana DUMORA
** Last update Sun Apr  2 22:11:34 2017 Maxime Desforest
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"

void	search_instructions(char ins, t_game *game, int i)
{
  if (ins - 1 >= 0 && ins - 1 < 16 && ins - 1 != 12 && ins - 1 != 13 && ins - 1
          != 14)
    {
      game->instruction[(int) ins - 1](game, i);
    }
  else
    game->heads[i].pos++;
}

void	moove_heads(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->nbr_heads)
    {
      if (game->heads[i].delay != 0)
	game->heads[i].delay--;
      else
	search_instructions(game->mem[game->heads[i].pos % MEM_SIZE], game, i);
      i++;
    }
}

void	show(t_game *game)
{
  static int	i = 0;

  if (i == game->show && game->show != -1)
    {
      show_mem(game->mem);
      i = 0;
    }
  i++;
}

int	vm_loop(t_game *game)
{
  int	end, save_cycle;

  end = 0;
  init_heads(game);
  save_cycle = game->cycle;
  while (end == 0)
    {
      show(game);
      if (game->cycle <= 0)
	{
	  end = check_win(game, save_cycle);
	  if (end != 0)
	    return (0);
	  game->cycle = save_cycle;
	}
      moove_heads(game);
      if (game->nbr_live >= NBR_LIVE)
	{
	  game->nbr_live = 0;
	  save_cycle -= CYCLE_DELTA;
	}
      game->cycle--;
      end = all_champions_dead(game);
    }
  return (0);
}
