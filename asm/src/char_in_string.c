/*
** char_in_string.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Mar 25 00:15:57 2017 Victor LE DANTEC
** Last update Sun Mar 26 22:11:53 2017 Victor LE DANTEC
*/

#include <stdlib.h>

int		char_in_string(char c, char *string)
{
  size_t	i;

  i = 0;
  while (string[i] != '\0')
    {
      if (c == string[i])
	return (1);
      i++;
    }
  return (EXIT_SUCCESS);
}
