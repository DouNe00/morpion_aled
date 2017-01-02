/*
** my_put_nbr.c for my_put_nbr.c in /home/delmon_m/rendu/Piscine_C_J03
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Wed Sep 30 12:31:48 2015 MD MD
** Last update Mon Nov 30 18:13:21 2015 cabanes gabriel
*/

int	my_put_nbr_k(unsigned int n)
{
  int	ret;
  int	i;

  i = 0;
  ret = n;
  if (n >= 10)
    {
      ret = n % 10;
      i = i + my_put_nbr_k(n / 10);
    }
  i = i + my_putchar_p(ret + 48);
  return (i);
}

int		my_putnbr_p(int nb)
{
  unsigned int	n;
  int		i;

  i = 0;
  n = nb;
  if (nb < 0)
    {
      i = i + my_putchar_p('-');
      n = nb * (-1);
    }
  return (i + my_put_nbr_k(n));
}
