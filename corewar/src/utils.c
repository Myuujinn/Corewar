/*
** utils.c for  in /home/maxime/Repo/CPE_2016_corewar/corewar/src/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Sun Apr  2 21:03:52 2017 Maxime Desforest
** Last update Mon Apr  3 00:42:36 2017 Victor LE DANTEC
*/

#include "libmy.h"

int	checkbase(char *base)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    {
      i++;
    }
  return (i);
}

int	is_negate(int i)
{
  if (i < 0)
    {
      my_putchar('-');
      return (-i);
    }
  return (i);
}

void	my_putnbr_base(int nbr, char *base)
{
  int	base_size, i;
  long	power, clone;

  if (nbr == 0)
    {
      my_putstr("00");
      return ;
    }
  if (nbr < 16)
    my_putchar('0');
  clone = is_negate((clone = nbr));
  base_size = checkbase(base);
  power = 1;
  while ((clone / power) != 0)
    power = power * base_size;
  power = power / base_size;
  while (power != 0)
    {
      i = 0;
      while ((i < base_size) && (power * i <= clone))
	i++;
      my_putchar(base[--i]);
      clone = clone % power;
      power = power / base_size;
    }
}
