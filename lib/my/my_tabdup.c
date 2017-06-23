/*
** my_tabdup.c for libmy-reboot in /home/victor/Libmy-reboot
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Jan  3 13:46:53 2017 Victor LE DANTEC
** Last update Sun Mar 26 22:40:12 2017 Victor LE DANTEC
*/

#include <stdlib.h>

void	*op_malloc(size_t);
char	*my_strdup(char *);

char		**my_tabdup(char **tab)
{
  size_t	i;
  char		**dupped;

  i = 0;
  while (tab[i] != 0)
    i++;
  dupped = op_malloc(sizeof(char *) * (i + 1));
  i = 0;
  while (tab[i] != 0)
    {
      dupped[i] = my_strdup(tab[i]);
      i++;
    }
  dupped[i] = 0;
  return (dupped);
}
