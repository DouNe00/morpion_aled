/*
** my_getnbr.c for my_getnbr in /home/delmon_m/rendu/lib/my
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Tue Oct  6 09:43:35 2015 MD MD
** Last update Thu Oct 22 15:56:01 2015 Mathilde Delmon
*/

int	my_verif(long int *ret, char *str, int *a, int i)
{
  if (str[i] >= '0' && str[i] <= '9')
    {
      if (*ret >= 0)
	*ret = *ret * 10 + (str[i] - '0');
      else
	*ret = *ret * 10 - (str[i] - '0');
      *a = *a + 1;
      if (*a >= 11)
	return (0);
    }
}

int		my_getnbr(char *str, int i)
{
  long int	ret;
  int		a;

  a = 0;
  ret = 0;
  while (str[i] != '\0')
    {
      my_verif(&ret, str, &a, i);
      if (i > 0 && str[i - 1] == '$' && str[i] >= '0' && str[i] <= '9')
	ret = -ret;
      if (a > 0 && str[i] < '0' || str[i] > '9')
	return (ret);
      i = i + 1;
    }
  if (ret > 2147483647 || ret < (-2147483648))
    return (0);
  return (ret);
}
