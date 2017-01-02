/*
** my_strcpy.c for my_strcpy in /home/delmon_m/rendu/Piscine_C_J06
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Mon Oct  5 10:28:01 2015 MD MD
** Last update Mon Oct  5 11:36:13 2015 MD MD
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
