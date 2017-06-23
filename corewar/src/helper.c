/*
** helper.c for  in /home/maxime/Repo/CPE_2016_corewar/corewar/src/
**
** Made by Maxime Desforest
** Login   <maxime.desforest@epitech.eu>
**
** Started on  Mon Mar 27 19:04:03 2017 Maxime Desforest
** Last update Mon Mar 27 19:09:42 2017 Maxime Desforest
*/

#include "libmy.h"

void    helper()
{
  my_putstr("USAGE\n\t\t./corewar [-dump nbr_cycle] [[-n prog_number]");
  my_putstr(" [-a load_address] prog_name] ...\nDESCRIPTION\n\t\t-dump");
  my_putstr(" nbr_cycle dumps the memory after the nbr_cycle execution ");
  my_putstr("(if the round isn’t\n\t\t\t\talready over) with the following");
  my_putstr(" format: 32 bytes/line in\n\t\t\t\thexadecimal");
  my_putstr(" (A0BCDEFE1DD3...)\n\t\t-n prog_number sets the next program’s");
  my_putstr(" number. By default, the first free number\n\t\t\t\tin the");
  my_putstr(" parameter order\n\t\t-a load_address sets the next program’s");
  my_putstr(" loading address. When no address is\n\t\t\t\tspecified,");
  my_putstr(" optimize the addresses so that the processes are as");
  my_putstr(" far\n\t\t\t\taway from each other as possible. The addresses");
  my_putstr(" are MEM_SIZE modulo\n");
}
