/*
** my_strupcase.c for my_strupcase in /home/delmon_m/rendu/Piscine_C_J06/ex_08
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 18:04:02 2015 MD MD
** Last update Mon Oct  5 18:15:25 2015 MD MD
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
