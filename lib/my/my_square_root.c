/*
** my_square_root.c for my_square_root in /home/delmon_m/rendu/Piscine_C_J05
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 08:51:59 2015 MD MD
** Last update Mon Oct  5 09:19:09 2015 MD MD
*/

int	my_square_root(int nb)
{
  int	a;
  int	b;

  a = 0;
  if (nb <= 0)
    {
      return (0);
    }
  while (a <= 46340 && a <= nb / 2)
    {
      if (a * a == nb)
	{
	  return (a);
	}
      a = a + 1;
    }
  return (0);
}
