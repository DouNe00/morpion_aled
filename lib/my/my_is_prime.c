/*
** my_is_prime.c for my_is_prime in /home/delmon_m/rendu/Piscine_C_J05
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 09:21:39 2015 MD MD
** Last update Tue Oct  6 09:57:08 2015 MD MD
*/

int	my_is_prime(int nombre)
{
  int	a;

  a = 2;
  if (nombre <= 1)
    {
      return (0);
    }
  else
    {
      while (a < 46340 && a <= (nombre / 2))
	{
	  if ((nombre % a) == 0)
	    {
	      return (0);
	    }
	  a = a + 1;
	}
    }
  return (1);
}
