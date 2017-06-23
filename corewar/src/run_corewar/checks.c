/*
** checks.c for Projects in /home/Projects/Projects/checks.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Tue Mar 28 16:02:25 2017 Moana DUMORA
** Last update Tue Mar 28 16:02:25 2017 Moana DUMORA
*/

#include "corewar.h"
#include "libmy.h"

int	all_champions_dead(t_game *game)
{
  int	i, nbr;

  i = nbr = 0;
  while (i < game->champ_nbr)
    {
      if (game->champs[i].isalive == -1)
	nbr++;
      i++;
    }
  if (nbr == game->champ_nbr)
    {
      alive_champ_wins(game);
      return (1);
    }
  return (0);
}

void	alive_champ_wins(t_game *game)
{
  int	i;

  i = 0;
  my_putstr("Equality between");
  while (i < game->champ_nbr)
    {
      if (game->champs[i].isalive != 0)
	{
	  my_putstr(", ");
	  my_putstr(game->champs[i].name);
	}
      i++;
    }
  my_putstr(" !!\n");
}

int	who_is_alive(t_game *game)
{
  int	i, nbr;

  i = nbr = 0;
  while (i < game->champ_nbr)
    {
      if (game->champs[i].isalive == 0)
	{
	  game->champs[i].isalive = -1;
	  my_putstr("player ");
	  my_put_nbr(game->champs[i].nbr);
	  my_putstr("(");
	  my_putstr(game->champs[i].name);
	  my_putstr(") is dead\n");
	}
      else if (game->champs[i].isalive == 1)
	{
	  game->champs[i].isalive = 0;
	  nbr++;
	}
      i++;
    }
  if (nbr == 1)
    return (2);
  return (0);
}

void	who_win(t_game *game)
{
  int	i;

  i = 0;
  while (i < game->champ_nbr)
    {
      if (game->champs[i].isalive != -1)
	{
	  my_putstr("player ");
	  my_put_nbr(game->champs[i].nbr);
	  my_putstr("(");
	  my_putstr(game->champs[i].name);
	  my_putstr(") WON !!\n");
	}
      i++;
    }
}

int	check_win(t_game *game, int save_cycle)
{
  int	ret;

  if (save_cycle <= 0)
    {
      alive_champ_wins(game);
      return (1);
    }
  ret = who_is_alive(game);
  if (ret == 2)
    {
      who_win(game);
      return (1);
    }
  return (0);
  (void)game;
}