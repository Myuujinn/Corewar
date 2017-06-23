/*
** my_put_nbr_base.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 20:50:17 2017 Victor LE DANTEC
** Last update Fri Jan  6 21:18:44 2017 Victor LE DANTEC
*/

#include <stdlib.h>

size_t	my_strlen(char *);
void	my_putchar(char);

void		my_put_nbr_base(ssize_t nbr, char *base)
{
  int		mod;
  int		start;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  mod = nbr % my_strlen(base);
  start = (nbr - mod) / my_strlen(base);
  if (start != 0)
    my_put_nbr_base(start, base);
  my_putchar(base[mod]);
}
