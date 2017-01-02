/*
** d_to_%.c for B1_Unix_System_Programming/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Wed Nov  4 13:55:16 2015 cabanes gabriel
** Last update Mon Nov 16 15:55:54 2015 cabanes gabriel
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_struct.h"

int	number(va_list ap)
{
  return (my_putnbr_p(va_arg(ap, int)));
}

int	charac(va_list ap)
{
  return (my_putchar_p(va_arg(ap, int)));
}

int	string(va_list ap)
{
  char	*str;

  str = va_arg(ap, char*);
  if (str == NULL)
    return (my_putstr_p("(null)"));
  return (my_putstr_p(str));
}

int	unsign(va_list ap)
{
  return (my_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
}
