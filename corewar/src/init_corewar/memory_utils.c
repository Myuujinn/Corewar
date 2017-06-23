/*
** memory_utils.c for Projects in /home/Projects/Projects/memory_utils.c
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Mon Mar 27 17:25:18 2017 Prenom Nom
** Last update Sun Apr  2 22:06:24 2017 Maxime Desforest
*/

#include <stdio.h>
#include "libmy.h"
#include "corewar.h"
#include "op.h"

void	init_heads(t_game *game)
{
  int	i;

  i = 0;
  game->heads = my_malloc(sizeof(t_heads) * game->champ_nbr);
  game->nbr_heads = game->champ_nbr;
  while (i < game->nbr_heads)
    {
      game->heads[i].delay = 0;
      game->heads[i].carry = 0;
      game->heads[i].who = i;
      game->heads[i].pos = game->champs[i].amorce;
      i++;
    }
  game->cycle = CYCLE_TO_DIE;
  game->nbr_live = 0;
}

void 	free_exit(int ex, char *message)
{
  op_free();
  my_putstr(message);
  exit(ex);
}

char 	*create_mem()
{
  char 	*mem;

  mem = op_malloc(sizeof(char) * (6 * 1024));
  my_memset(mem, 0, 6 * 1024);
  return (mem);
}

void	show_mem(char *mem)
{
  int	x, y, z;

  x = z = 0;
  while (x < 6 * 1024)
    {
      y = 0;
      my_putstr("\x1B[0mline 0x");
      my_putnbr_base(z++ + 1, "0123456789ABCDEF");
      my_putchar(':');
      while (y < 32)
	{
	  if (mem[x] != '\0')
          {
            my_putstr(" \x1B[32m");
	    my_putnbr_base((unsigned char)mem[x++] , "0123456789ABCDEF");
          }
	  else
          {
            my_putstr(" \x1B[0m");
	    my_putnbr_base((unsigned char)mem[x++] , "0123456789ABCDEF");
          }
	  y++;
	}
      my_putchar('\n');
    }
}
