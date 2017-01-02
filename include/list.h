/*
** list.h for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_select
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Mon Nov 30 16:25:30 2015 cabanes gabriel
** Last update Thu Dec  3 11:38:34 2015 cabanes gabriel
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  int		suppr;
  int		first;
  int		underline;
  int		select;
  char		*data;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

#endif LIST_H_
