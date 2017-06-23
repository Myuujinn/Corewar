/*
** error.c for asm in /home/victor/ASM/CPE_2016_corewar
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Mar  9 13:29:22 2017 Victor LE DANTEC
** Last update Sun Mar 26 22:06:19 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

int	asm_error(ssize_t line, char *file, char *error)
{
  my_puterr("asm: ");
  my_puterr(file);
  my_puterr(": line ");
  my_put_nbr(line);
  my_puterr(": ");
  my_puterr(error);
  my_puterr("\n");
  return (EXIT_FAILURE);
}

int	error_return(char *name, char *error)
{
  my_puterr(name);
  my_puterr(": ");
  my_puterr(error);
  return (EXIT_FAILURE);
}

void	error_msg(char *error, char exit_code)
{
  write(2, error, my_strlen(error));
  exit(exit_code);
}
