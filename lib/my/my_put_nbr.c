/*
** my_put_nbr.c for my_put_nbr.c in /home/delmon_m/rendu/Piscine_C_J03
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Wed Sep 30 12:31:48 2015 MD MD
** Last update Thu Oct  1 18:26:19 2015 MD MD
*/

int	my_put_nbr_w(unsigned int n)
{
  int	ret;

  ret = n;
  if (n >= 10)
    {
      ret = n % 10;
      my_put_nbr_w(n / 10);
    }
  my_putchar(ret + 48);
  return (0);
}

int		my_put_nbr(int nb)
{
  unsigned int	n;

  n = nb;
  if (nb < 0)
    {
      my_putchar('-');
      n = nb * (-1);
    }
  my_put_nbr_w(n);
  return (0);
}
