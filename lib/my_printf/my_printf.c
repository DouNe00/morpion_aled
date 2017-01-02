/*
** my_printf.c for  in B1_Unix_System_Programming/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Wed Nov  4 12:31:30 2015 cabanes gabriel
** Last update Mon Nov 16 16:02:44 2015 cabanes gabriel
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my_struct.h"

void	init_struct(t_params *stock)
{
  stock->count = 0;
  stock->j = 0;
  stock->i = 0;
  stock->tab[0] = &number;
  stock->tab[1] = &number;
  stock->tab[2] = &charac;
  stock->tab[3] = &string;
  stock->tab[4] = &pointer;
  stock->tab[5] = &unsign;
  stock->tab[6] = &octal;
  stock->tab[7] = &binary;
  stock->tab[8] = &hexa_less;
  stock->tab[9] = &hexa_upp;
  stock->tab[10] = &non_printable;
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  t_params	stock;

  init_struct(&stock);
  va_start(ap, str);
  if (str == NULL)
    return (-1);
  while (str[stock.i] != '\0')
    {
      if (str[stock.i] == '%' && str[stock.i + 1] != '\0')
	{
	  while (str[stock.i + 1] == ' ')
	    stock.i++;
	  distrib(str, stock.i, &stock, ap);
	  stock.i++;
	}
      else
	stock.j = stock.j + my_putchar_p(str[stock.i]);
      stock.i++;
    }
  va_end(ap);
  return (stock.j);
}
