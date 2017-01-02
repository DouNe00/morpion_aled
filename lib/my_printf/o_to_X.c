/*
** o_to_S.c for  in B1_Unix_System_Programming/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Wed Nov  4 17:14:56 2015 cabanes gabriel
** Last update Wed Nov 11 10:31:39 2015 cabanes gabriel
*/

#include <stdarg.h>

int	octal(va_list ap)
{
  return (my_putnbr_base(va_arg(ap, int), "01234567"));
}

int	binary(va_list ap)
{
  return (my_putnbr_base(va_arg(ap, unsigned int), "01"));
}

int	hexa_less(va_list ap)
{
  return (my_putnbr_base(va_arg(ap, int), "0123456789abcdef"));
}

int	hexa_upp(va_list ap)
{
  return (my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF"));
}
