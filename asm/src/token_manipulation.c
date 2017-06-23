/*
** token_manipulation.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sun Mar 26 21:17:48 2017 Victor LE DANTEC
** Last update Sun Mar 26 21:20:20 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

char		*remove_comments(char *string)
{
  size_t	i;

  i = 0;
  while (string[i] != '\0' && string[i] != COMMENT_CHAR)
    i++;
  string[i] = '\0';
  return (string);
}

void		print_tokens(char **tokens)
{
  size_t	i;
  int		iden;

  i = 0;
  while (tokens[i] != NULL)
    {
      iden = identifier_token(tokens[i]);
      if (iden == 1)
        my_putstr("Label -> ");
      else if (iden == 2)
	my_putstr("Instruction -> ");
      else if (iden == 3)
        my_putstr("Register -> ");
      else if (iden == 4)
	my_putstr("Direct -> ");
      else if (iden == 5)
	my_putstr("Indirect -> ");
      else if (iden == 0)
	my_putstr("Unknown -> ");
      my_putstr(tokens[i]);
      my_putchar('\n');
      i++;
    }
}
