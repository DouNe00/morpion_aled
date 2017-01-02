/*
** my_strncmp.c for my_strncmp in /home/delmon_m/rendu/Piscine_C_J06/ex_07
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 17:34:10 2015 MD MD
** Last update Tue Oct  6 10:04:55 2015 MD MD
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int   i;
  int   dif;
  
  i = 1;
  nb = nb + 1;
  dif = 0;
  while (s1[i - 1] != '\0' && s2[i - 1] != '\0' && i != nb)
    {
      if (s1[i] != s2[i])
	{
	  dif = s1[i] - s2[i];
	  return (dif);
	}
      i = i + 1;
    }
}
