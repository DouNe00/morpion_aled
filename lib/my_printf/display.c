/*
** init.c for  in B1_Unix_System_Programming/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Wed Nov  4 13:08:10 2015 cabanes gabriel
** Last update Mon Nov 16 15:30:44 2015 cabanes gabriel
*/

#include <stdarg.h>
#include "my_printf.h"
#include "my_struct.h"

int	distrib(char *str, int i, t_params *stock, va_list ap)
{
  char	*flag;
  int	j;

  j = 0;
  stock->count = 0;
  flag = "dicspuobxXS";
  while (flag[stock->count] != '\0')
    {
      if (flag[stock->count] == str[stock->i + 1])
	stock->j = stock->j + stock->tab[stock->count](ap);
      else
	j++;
      stock->count++;
    }
  if (j == stock->count)
    {
      if (str[stock->i + 1] == '%')
	stock->j = stock->j + my_putchar_p('%');
      else
	{
	  stock->j = stock->j + my_putchar_p('%');
	  stock->j = stock->j + my_putchar_p(str[stock->i + 1]);
	}
    }
  return (stock->j);
}
