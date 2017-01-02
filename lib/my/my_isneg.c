/*
** my_isneg.c for my_isneg.c in /home/delmon_m/rendu/Piscine_C_J03
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Wed Sep 30 10:03:43 2015 MD MD
** Last update Tue Oct  6 09:52:41 2015 MD MD
*/

int	my_isneg(int nb)
{
  if (nb < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
