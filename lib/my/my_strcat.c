/*
** my_strcat.c for my_strcat.c in /home/delmon_m/rendu/Piscine_C_J07
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Tue Oct  6 10:58:49 2015 MD MD
** Last update Sun Nov 29 10:58:27 2015 cabanes gabriel
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*cpy;

  i = 0;
  j = 0;
  cpy = malloc(my_strlen(dest) + my_strlen(src) + 1);
  while (dest[i] != '\0')
    {
      cpy[i] = dest[i];
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      cpy[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  cpy[i] = '\0';
  return (cpy);
}
