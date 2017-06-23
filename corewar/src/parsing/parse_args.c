/*
** parse_args.c for Projects in /home/Projects/Projects/parse_args.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Mon Mar 27 18:51:09 2017 Moana DUMORA
** Last update Sun Apr  2 22:14:56 2017 Maxime Desforest
*/

#include <stdlib.h>
#include <stdio.h>
#include "corewar.h"
#include "libmy.h"

int	count_champs(char **av)
{
  int	i, len, nbr;

  i = 1;
  nbr = 0;
  while (av[i] != NULL)
    {
      len = my_strlen(av[i]) - 1;
      if (av[i][len] == 'r' && av[i][len - 1] == 'o' &&
       av[i][len - 2] == 'c' && av[i][len - 3] == '.')
	nbr++;
      i++;
    }
  return (nbr);
}

void 	set_defaults_values(t_game *game)
{
  int	i;
  int 	j;

  i = 0;
  game->show = -1;
  while (i < game->champ_nbr)
    {
      j = 1;
      while (j < REG_NUMBER)
	game->champs[i].reg[j++] = 0;
      game->champs[i].amorce = 0;
      game->champs[i].nbr = i;
      game->champs[i].reg[0] = i;
      game->champs[i].isalive = 0;
      i++;
    }
}

void	help(char **av)
{
  int	i;

  i = 1;
  while (av[i] != NULL)
    {
      if (my_strcmp("-h", av[i]) == 0)
	{
	  helper();
	  exit(0);
	}
      i++;
    }
}

void	init_champs(t_game *game, char **av)
{
  int	i, j, len;

  set_defaults_values(game);
  j = i = 0;
  while (av[++i] != NULL)
    {
      len = my_strlen(av[i]) - 1;
      if (my_strcmp("-n", av[i]) == 0 && av[i + 1] != NULL && j <
      game->champ_nbr)
	{
	  game->champs[j].reg[0] = my_getnbr(av[i + 1]);
	  game->champs[j].nbr = my_getnbr(av[i++ + 1]);
	}
      else if (my_strcmp("-a", av[i]) == 0 && av[i + 1] != NULL && j <
      game->champ_nbr)
	game->champs[j].amorce = my_getnbr(av[i++ + 1]);
      else if (my_strcmp("-dump", av[i]) == 0 && av[i + 1] != NULL)
	game->show = my_getnbr(av[i++ + 1]);
      else if (av[i][len] == 'r' && av[i][len - 1] == 'o' &&
	  av[i][len - 2] == 'c' && av[i][len - 3] == '.')
	read_champ_prog(av[i], game, j++);
      else
	exit(84);
    }
}
