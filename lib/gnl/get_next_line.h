/*
** get_next_line.h for get_next_line in /home/victor/CPE/CPE_2017_getnextline
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Jan  2 11:14:11 2017 Victor LE DANTEC
** Last update Sun Apr  2 16:20:03 2017 Victor LE DANTEC
*/

#pragma once

#define READ_SIZE 200

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libmy.h"

char	*get_next_line(const int fd);
