/*
** p_and_S.c for  in /home/cabane_g/rendu/Unix_System/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Fri Nov  6 20:12:04 2015 cabanes gabriel
** Last update Mon Nov 16 15:32:26 2015 cabanes gabriel
*/
#include <stdlib.h>
#include "my_printf.h"

int			pointer(va_list ap)
{
  unsigned long int	nb;

  nb = va_arg(ap, unsigned long int);
  if (nb == 0)
    return (my_putstr_p("(nil)"));
  my_putstr_p("0x");
  return (2 + my_putnbr_base(nb, "0123456789abcdef"));
}

int	non_printable(va_list ap)
{
  char	*str;
  int	i;

  i = 0;
  str = va_arg(ap, char*);
  while	(str[i] != '\0')
    {
      if (str[i] < 8)
	put_some_things(str, i);
      else if (str[i] >= 8 && str[i] < 32)
	{
	  my_putstr_p("\\0");
	  my_putnbr_base(str[i], "01234567");
	}
      else if (str[i] == 127)
	{
	  my_putchar_p('\\');
	  my_putnbr_base(str[i], "01234567");
	}
      else
	my_putchar_p(str[i]);
      i = i + 1;
    }
  return (i);
}

void	put_some_things(char *str, int i)
{
  my_putstr_p("\\00");
  my_putnbr_base(str[i], "01234567");
}
