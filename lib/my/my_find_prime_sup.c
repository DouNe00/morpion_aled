/*
** my_find_prime_sup.c for my_find_prime_sup in /home/delmon_m/rendu/Piscine_C_J05
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 09:45:14 2015 MD MD
** Last update Mon Oct  5 10:17:35 2015 MD MD
*/

int	my_find_prime_sup(int nb)
{
  if (nb <= 1)
    {
      return (2);
    }
  if (my_is_prime(nb) == 1)
    {
      return (nb);
    }
  while (my_is_prime(nb) == 0)
    {
      nb = nb + 1;
    }
  return (nb);
}
