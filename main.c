/*
** main.c for  in /home/cabane_g/rendu/Unix_System/PSU_2015_my_popup
** 
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
** 
** Started on  Mon Nov 30 11:30:34 2015 cabanes gabriel
** Last update Sun Dec 13 19:52:28 2015 cabanes gabriel
*/

#include <ncurses.h>
#include <stdlib.h>
#include "list.h"

t_list		*manage_list(t_list *list, int ac, t_list *lastelem)
{
  SCREEN	*win;
  int		kay;

  win = newterm(NULL, stderr, stdin);
  cbreak();
  noecho();
  curs_set(0);
  box(stdscr, 0, 0);
  keypad(stdscr, TRUE);
  display(list, ac, 1, 1);
  list = move_inlist(list, ac, lastelem);
  endwin();
  return (list);
}

void		return_value(t_list *list, int ac, t_list *firstelem)
{
  int		i;
  i = 0;

  while (list->next->first != 1)
    {
      if (list->select == 1)
	i++;
      list = list->next;
    }
  if (list->select == 1)
    i++;
  while (list->next->first != 1)
    list = list->next;
  list = list->next;
  while (i)
    {
      if (list->select == 1)
	((i-- == 1) ?  my_printf("%s", list->data) : my_printf("%s ", list->data));
      list = list->next;
    }
  my_putchar('\n');
  exit(0);
}

int		main(int argc, char **argv)
{
  t_list	*list;
  t_list	*lastelem;
  t_list	*firstelem;
  int		i;

  if (argc == 1)
    {
      write(2, "This programm needs more arguments\n", 36);
      return (1);
    }
  i = argc - 1;
  list = NULL;
  firstelem = NULL;
  lastelem = NULL;
  while (i > 0)
    my_putin_list(&list, &lastelem, argv[i--], i);
  firstelem = list;
  lastelem->next = firstelem;
  firstelem->prev = lastelem;
  list = manage_list(list, argc - 1, &firstelem);
  firstelem->data = list->data;
  return_value(list, argc - 1, firstelem);
  return (0);
}
