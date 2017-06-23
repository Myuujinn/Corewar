/*
** my_better_strtok.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Sat Mar 25 00:56:53 2017 Victor LE DANTEC
** Last update Tue Mar 28 18:29:38 2017 Victor LE DANTEC
*/

#include "libmy.h"
#include "op.h"

size_t		token_nb(char *input)
{
  size_t	i;
  size_t	nb;

  i = nb = 0;
  while (input[i] != '\0')
    {
      if (input[i] != '\t' && input[i] != ' ' && input[i] != SEPARATOR_CHAR)
	{
	  nb++;
	  while (input[i] != '\0' && input[i] != '\t'
		 && input[i] != ' ' && input[i] != SEPARATOR_CHAR)
	    i++;
	}
      else
	i++;
    }
  return (nb);
}

size_t		word_size(char *input)
{
  size_t	i;

  i = 0;
  while (input[i] != '\0' && input[i] != '\t'
	 && input[i] != ' ' && input[i] != SEPARATOR_CHAR)
    i++;
  return (i);
}

char		**tokenizer(char *input)
{
  char		**tokens;
  size_t	i;
  size_t	index;
  size_t	j;

  tokens = op_malloc(sizeof(char *) * (token_nb(input) + 1));
  i = index = 0;
  while (input[i] != '\0')
    if (input[i] != '\t' && input[i] != ' ' && input[i] != SEPARATOR_CHAR)
      {
	tokens[index] = op_malloc(word_size(input + i) + 3);
	j = 0;
	while (input[i] != '\0' && input[i] != '\t'
	       && input[i] != ' ' && input[i] != SEPARATOR_CHAR)
	  tokens[index][j++] = input[i++];
	tokens[index++][j] = '\0';
      }
    else
      i++;
  tokens[index] = 0;
  return (tokens);
}
