/*
** my_power_rec.c for my_power_rec in /home/delmon_m/rendu/Piscine_C_J05
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Sat Oct  3 10:44:52 2015 MD MD
** Last update Sat Oct  3 10:59:06 2015 MD MD
*/

int	my_power_rec(int nb, int power)
{
  int	nbr;

  nbr = nb;
  if (power < 0)
    return (0);
  else if (power == 0)
    return (1);
  else if (power > 1)
    {
      return (nbr * (my_power_rec(nbr, power - 1)));
    }
}
