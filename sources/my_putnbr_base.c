/*
** my_putnbr_base.c for CPool_Day06 in /home/acoruble/delivery/CPool_Day06
**
** Made by Arthur CORUBLE
** Login  <acoruble@epitech.net>
**
** Started on  mar. oct. 11 18:30:45 2016 Arthur CORUBLE
** Last update mer. févr. 08 10:31:30 2017 Arthur CORUBLE
*/

#include "../include/malloc.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

void	my_putnbr_base(uintptr_t nbr, char *base)
{
  int	base_len;
  int	nb;

  nb = 1;
  base_len = my_strlen(base);
  if (base_len == 1)
  {
     while (nb < nbr)
     {
      my_putchar(base[0]);
      nb = nb + 1;
     }
     return;
  }
  nb = 1;
  if (nbr < 0)
  {
    nbr = nbr * -1;
    my_putchar('-');
    nb = nb + 1;
  }
  if (nbr >= (base_len - 1))
      my_putnbr_base((nbr / base_len), base);
  my_putchar(base[nbr - ((nbr / base_len)*base_len)]);
  return;
}
