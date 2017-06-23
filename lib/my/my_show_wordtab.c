/*
** my_show_wordtab.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Jan  6 20:56:39 2017 Victor LE DANTEC
** Last update Fri Jan  6 21:13:01 2017 Victor LE DANTEC
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putstr(char *);

void		my_show_wordtab(char **tab)
{
  size_t	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i++]);
      write(1, "\n", 1);
    }
}
