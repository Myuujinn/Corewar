/*
** main.c for asm in /home/victor/ASM/CPE_2016_corewar
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Wed Mar  8 18:40:11 2017 Victor LE DANTEC
** Last update Thu Mar 30 11:37:22 2017 Victor LE DANTEC
*/

#include "asm.h"
#include "libmy.h"

int	main(int argc, char **argv)
{
  int	i;
  int	return_val;

  if (argc < 2)
    error_msg("Usage: ./asm file_name[.s] ....\n", EXIT_FAILURE);
  i = 1;
  while (i != argc)
    if ((return_val = compile_champion(argv[i++])) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  op_free();
  return (EXIT_SUCCESS);
}
