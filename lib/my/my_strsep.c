/*
** my_strsep.c for exec in /home/moana/Projects/PSU-Projects/B_PSU_2016_my_exec/
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu>
**
** Started on  Tue Jan  3 16:47:05 2017 Moana DUMORA
** Last update Sun Mar 26 22:38:19 2017 Victor LE DANTEC
*/

#include "libmy.h"

int	count_words(char *sen, char *delim)
{
  int	i;
  int	cmp;
  int	k;
  int	nbr;

  i = nbr = cmp = 0;
  while (sen[i] != '\0')
    {
      k = cmp = 0;
      while ((size_t)k < my_strlen(delim))
        {
          if (sen[k + i] == delim[k])
            cmp++;
          k++;
        }
      if (cmp == k)
        nbr++;
      i++;
    }
  return (nbr + 1);
}

char	*reset_it(char *str, int i)
{
  int	k;
  char	*final;

  k = 0;
  final = op_malloc(sizeof(char) * (my_strlen(str)));
  while ((size_t)i < my_strlen(str))
    {
      final[k] = str[i];
      k++;
      i++;
    }
  final[k] = '\0';
  return (final);
}

int	check_delim(char *str, char *delim, int i)
{
  int	k;
  int	cmp;

  k = cmp = 0;
  while ((size_t)k < my_strlen(delim))
    {
      cmp += (str[i + k] == delim[k]) ? 1 : 0;
      k++;
    }
  if (cmp == k)
    return (0);
  else
    return (1);
}

char	*my_strsep(char **str, char *delim)
{
  char	*final;
  int	i;
  int	k;

  i = 0;
  while (str[0][i] != '\0')
    {
      if (check_delim(str[0], delim, i) == 0)
        {
          final = op_malloc(sizeof(char) * (i + 2));
          k = 0;
          while (k < i)
	    {
	      final[k] = str[0][k];
	      k++;
	    }
	  final[k] = '\0';
          str[0] = reset_it(str[0], i + 1);
          return (final);
        }
      if (str[0][i++ + 1] == '\0')
        str[0] = my_strcat(str[0], delim);
    }
  return (NULL);
}
