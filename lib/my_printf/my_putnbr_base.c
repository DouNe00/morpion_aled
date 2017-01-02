/*
** my_putnbr_base.c for  in /home/cabane_g/rendu/Piscine_C_J06/ex_16
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Tue Oct  6 11:52:35 2015 cabanes gabriel
** Last update Mon Nov 16 11:28:10 2015 cabanes gabriel
*/

int	my_putnbr_base(unsigned long int nbr, char *base)
{
  int	ret;
  int	sbase;
  int	i;

  i = 0;
  sbase = my_strlen_p(base);
  ret = nbr;
  if (nbr >= sbase)
    {
      ret = nbr % sbase;
      i = i + my_putnbr_base((nbr / sbase), base);
    }
  i = i + my_putchar_p(base[ret]);
  return (i);
}
