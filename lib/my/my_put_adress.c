/*
** my_put_adress.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 19:48:10 2017 Victor LE DANTEC
** Last update Fri Jan  6 19:50:36 2017 Victor LE DANTEC
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char);

void	 my_put_adress(long nb)
{
  long	result;
  long	divider;
  int	size_base;
  char	*base;

  base = "0123456789abcdef";
  size_base = 16;
  divider = 1;
  write(1, "0x", 2);
  while ((nb / divider) >= size_base)
    divider = divider * size_base;
  while (divider > 0)
    {
      result = (nb / divider) % size_base;
      my_putchar(base[result]);
      divider = divider / size_base;
    }
}
