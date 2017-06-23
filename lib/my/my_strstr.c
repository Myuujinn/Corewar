/*
** my_strstr.c for my_strstr in /home/victor/ASM/CPE_2016_corewar
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Mon Mar 13 17:46:28 2017 Victor LE DANTEC
** Last update Tue Mar 14 15:49:36 2017 Victor LE DANTEC
*/

#include "libmy.h"

char		*my_strstr(char *haystack, char *needle)
{
  size_t	j;

  j = 0;
  if (haystack[0] != '\0')
    {
      while (needle[j] != '\0')
	{
	  if (needle[j] != haystack[j])
	    return (my_strstr(haystack + 1, needle));
	  j++;
	}
      return (haystack);
    }
  return (NULL);
}
