/*
** store_champ_info.c for corewar in /home/stickboy/Projects/CPE-Projects/CPE_2016_corewar/corewar/src/init_champ/
**
** Made by Moana DUMORA
** Login   <moana.dumora@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 27 13:44:35 2017 Moana DUMORA
** Last update Fri Mar 31 23:35:47 2017 Maxime Desforest
*/

#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"
#include "op.h"
#include "libmy.h"

void    give_me_a_name(header_t *header, int fd)
{
  read(fd, &header->magic, sizeof(int));
  read(fd, &header->prog_name, sizeof(header->prog_name) + 3);
  read(fd, &header->prog_size, sizeof(int));
  read(fd, &header->comment, COMMENT_LENGTH + 1);
}

void	write_champ(t_game *game, int fd, int j)
{
  char 	buff[1];
  int 	x;

  buff[0] = '\0';
  x = game->champs[j].amorce + MEM_SIZE - 3;
  while (read(fd, buff, 1) != 0)
    {
      if (game->mem[x % MEM_SIZE] != '\0')
	free_exit(84, "Dont try to overwrite other champs\n");
      game->mem[x % MEM_SIZE] = buff[0];
      x++;
    }
}

void	read_champ_prog(char *name, t_game *game, int j)
{
  header_t      header;
  int   fd;

  if ((fd = open(name, S_IRUSR)) == -1)
    free_exit(84, "Error while opening champion\n");
  give_me_a_name(&header, fd);
  game->champs[j].name = op_malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
  my_memset(game->champs[j].name, 0 , PROG_NAME_LENGTH + 1);
  my_strcpy(game->champs[j].name, header.prog_name);
  write_champ(game, fd, j);
  close(fd);
}
