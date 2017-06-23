/*
** parser_utils.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Mar 14 21:59:26 2017 Victor LE DANTEC
** Last update Sun Mar 26 22:50:14 2017 Victor LE DANTEC
*/

#include "libmy.h"

char		*clean_str(char *line)
{
  size_t	i;

  i = my_strlen(line) - 1;
  while (i > 0 && (line[i] == ' ' || line[i] == '\t'))
    i--;
  line[i + 1] = '\0';
  return (line);
}

char		*str_trunc(char *str, size_t index)
{
  str[index] = '\0';
  return (str);
}

int		empty_line(char *line)
{
  size_t	i;

  i = 0;
  while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
    i++;
  if (line[i] != '\0')
    return (1);
  return (EXIT_SUCCESS);
}
