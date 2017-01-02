/*
** my_strncat.c for my_strncat in /home/delmon_m/rendu/Piscine_C_J07/ex_03
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Tue Oct  6 11:27:46 2015 MD MD
** Last update Wed Oct  7 08:56:41 2015 MD MD
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int   i;
  int   j;
  int	n;

  i = 0;
  j = 0;
  n = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while ((n < nb) && (src[j] != '\0'))
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
      n = n + 1;
    }
  dest[i] = '\0';
  return (dest);
}
