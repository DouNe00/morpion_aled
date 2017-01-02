/*
** my_strlen.c for my_strlen.c in /home/delmon_m/rendu/Piscine_C_J04
** 
** Made by MD MD
** Login   <delmon_m@epitech.net>
** 
** Started on  Thu Oct  1 11:44:22 2015 MD MD
** Last update Mon Nov 16 11:31:50 2015 cabanes gabriel
*/

int	my_strlen_p(char *str)
{
  int	len;

  len = 0;
  while (str[len] != '\0')
    {
      len = len + 1;
    }
  return (len);
}
