/*
** summ_stdarg.c for  in /home/cabane_g/rendu/PSU_2015_my_printf_bootstap
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Tue Nov  3 15:18:20 2015 cabanes gabriel
** Last update Wed Nov  4 14:34:13 2015 cabanes gabriel
*/

#include <stdarg.h>

int		sum_stdarg(int i, int nb, ...)
{
  va_list	ap;
  int		result;

  result = 0;
  va_start(ap, nb);
  if (i == 0)
    {
      while (nb != 0)
	{
	  result = result + va_arg(ap, int);
	  nb--;
	}
    }
  else if (i == 1)
    {
      while (nb != 0)
	{
	  result = result + my_strlen(va_arg(ap, char*));
	  nb--;
	}
    }
  va_end(ap);
  return (result);
}
