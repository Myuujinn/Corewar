/*
** big_endian_converter.c for asm in /home/victor/ASM/CPE_2016_corewar/asm
** 
** Made by Victor LE DANTEC
** Login   <victor.le-dantec@epitech.eu>
** 
** Started on  Thu Mar 23 16:46:48 2017 Victor LE DANTEC
** Last update Wed Mar 29 00:03:51 2017 Victor LE DANTEC
*/

int	little_to_big_int(int val)
{
  val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
  return ((val << 16) | ((val >> 16) & 0xFFFF));
}

short	little_to_big_short(short val)
{
  return ((val << 8) | ((val >> 8) & 0xFF));
}
