/*
** lexer.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Fri Mar 24 23:53:26 2017 Victor LE DANTEC
** Last update Thu Mar 30 16:34:10 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

int	is_instruction(char *token)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strcmp(token, op_tab[i].mnemonique) == 0)
	return (1);
      i++;
    }
  return (EXIT_SUCCESS);
}

int		is_register(char *token)
{
  ssize_t	i;

  i = 1;
  while (token[i] != '\0')
    {
      if (!(token[i] >= '0' && token[i] <= '9'))
	return (EXIT_SUCCESS);
      i++;
    }
  i = my_getnbr(token + 1);
  if (i <= 0 || i > REG_NUMBER)
    return (EXIT_SUCCESS);
  return (1);
}

int		is_label(char *token)
{
  size_t	i;

  i = 0;
  while (token[i + 1] != '\0')
    {
      if (char_in_string(token[i], LABEL_CHARS) == 0)
	return (EXIT_SUCCESS);
      i++;
    }
  if (token[i] != LABEL_CHAR)
    return (EXIT_SUCCESS);
  return (1);
}

int		is_indirect(char *token)
{
  size_t	i;

  i = 0;
  if (token[i] == LABEL_CHAR)
    return (1);
  if (token[i] == '-')
    i++;
  while (token[i] != '\0')
    {
      if (!(token[i] >= '0' && token[i] <= '9'))
	return (EXIT_SUCCESS);
      i++;
    }
  return (1);
}

int		identifier_token(char *token)
{
  if (token == 0)
    return (EXIT_SUCCESS);
  if (is_label(token) == 1)
    return (1);
  if (is_instruction(token) == 1)
    return (2);
  if (token[0] == 'r' && is_register(token) == 1)
    return (3);
  if (token[0] == DIRECT_CHAR)
    return (4);
  if (is_indirect(token) == 1)
    return (5);
  return (EXIT_SUCCESS);
}
