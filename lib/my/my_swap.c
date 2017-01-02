/*
** my_swap.c for my_swap.c in /home/delmon_m/rendu/Piscine_C_J04
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Thu Oct  1 10:09:59 2015 MD MD
** Last update Thu Oct  1 22:49:05 2015 MD MD
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = 0;
  if (a == 0 || b == 0)
    {
      return (-1);
    }
  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
