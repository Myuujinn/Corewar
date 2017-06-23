/*
** args_check.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Mar 27 19:13:27 2017 Victor LE DANTEC
** Last update Mon Mar 27 19:29:25 2017 Victor LE DANTEC
*/

#include "asm.h"

int	has_arg(int index, int arg_nb, int arg)
{
  if (arg == T_REG && (op_tab[index].type[arg_nb] & T_REG) == T_REG)
    return (1);
  if (arg == T_DIR && (op_tab[index].type[arg_nb] & T_DIR) == T_DIR)
    return (1);
  if (arg == T_IND && (op_tab[index].type[arg_nb] & T_IND) == T_IND)
    return (1);
  return (EXIT_SUCCESS);
}
