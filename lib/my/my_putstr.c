/*
** my_putstr.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 20:52:23 2017 Victor LE DANTEC
** Last update Sun Mar 26 15:03:06 2017 Victor LE DANTEC
*/

#include <unistd.h>

size_t	my_strlen(char *);
void	my_putchar(char);

void	my_putstr_line(char *str)
{
  write(1, str, my_strlen(str));
  my_putchar('\n');
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
}
