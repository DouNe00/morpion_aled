/*
** my_select.h for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_select
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Tue Dec  1 11:35:07 2015 cabanes gabriel
** Last update Tue Dec  1 13:54:48 2015 cabanes gabriel
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

int     display(t_list *list);
void    move_inlist(t_list *list, int ac);
void    clear_underline(t_list *list);
void    manage_print(t_list **list, int key);
int     manage_list(t_list *list, int ac);
void    nothing();

#endif /* MY_SELECT_H_ */
