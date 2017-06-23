/*
** coding_byte.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Tue Mar 28 23:48:28 2017 Victor LE DANTEC
** Last update Tue Mar 28 23:50:43 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

void	get_byte(char *coding_byte, int i, int type)
{
  if (i == 1 && type == 3)
    *coding_byte += 64;
  else if (i == 1 && type == 4)
    *coding_byte += 128;
  else if (i == 1 && type == 5)
    *coding_byte += 192;
  else if (i == 2 && type == 3)
    *coding_byte += 16;
  else if (i == 2 && type == 4)
    *coding_byte += 32;
  else if (i == 2 && type == 5)
    *coding_byte += 48;
  else if (i == 3 && type == 3)
    *coding_byte += 4;
  else if (i == 3 && type == 4)
    *coding_byte += 8;
  else if (i == 3 && type == 5)
    *coding_byte += 12;
}

char	*get_coding_byte(char **tokens)
{
  int	i;
  char	*coding_byte;

  i = 1;
  coding_byte = op_malloc(sizeof(char));
  *coding_byte = 0;
  while (tokens[i] != 0)
    {
      get_byte(coding_byte, i, identifier_token(tokens[i]));
      i++;
    }
  return (coding_byte);
}
