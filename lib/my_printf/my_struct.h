/*
** my_struct.h for  in /home/cabane_g/rendu/Unix_System/my_printf/PSU_2015_my_printf
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Tue Nov 10 17:53:39 2015 cabanes gabriel
** Last update Thu Nov 12 13:55:47 2015 cabanes gabriel
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

typedef	struct	s_params
{
  int		count;
  int		i;
  int		j;
  int		(*tab[11])(va_list);
}		t_params;

#endif /* MY_STRUCT_H_ */
