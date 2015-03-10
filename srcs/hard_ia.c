/*
** hard_ia.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1/srcs
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb 10 16:53:56 2015 Antoine Zanardi
** Last update Tue Feb 10 18:41:23 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"allum1.h"
#include	"my.h"

void		lowest_row(t_list **list, t_choice *easy)
{
  int		compt;
  unsigned int	low;
  int		bool;
  t_list	*tmp;

  tmp = *list;
  bool = 0;
  compt = 1;
  while (tmp != NULL)
    {
      if (bool == 0)
	{
	  easy->row = compt;
	  low = tmp->nombre;
	  bool = 1;
	}
      else if (low > tmp->nombre)
	{
	  easy->row = compt;
	  low = tmp->nombre;
	}
      compt++;
      tmp = tmp->next;
    }
  free(tmp);
}

void		classic_move(t_list **list, t_choice *hard)
{
  int		compt_row;
  t_list	*tmp;

  lowest_row(list, hard);
  tmp = *list;
  compt_row = 1;
  while (compt_row < hard->row)
    {
      tmp = tmp->next;
      compt_row++;
    }
  hard->number = tmp->nombre;
}

void		two_lines(t_list **list, t_choice *hard)
{
  bigger_row(list, hard);
  if (hard->row == 1)
    {
      if ((*list)->next->nombre == 1)
	hard->number = (*list)->nombre;
      else if ((*list)->next->nombre != (*list)->nombre)
	hard->number = (*list)->nombre - (*list)->next->nombre;
      else if ((*list)->next->nombre == (*list)->nombre)
	hard->number = 1;
    }
  else if (hard->row == 2)
    {
      if ((*list)->nombre == 1)
	hard->number = (*list)->next->nombre;
      else if ((*list)->nombre != (*list)->next->nombre)
	hard->number = (*list)->next->nombre - (*list)->nombre;
      else if ((*list)->next->nombre == (*list)->nombre)
	hard->number = 1;
    }
}

void		one_line(t_list *list, t_choice *hard)
{
  hard->row = 1;
  hard->number = list->nombre - 1;
}

int		hard_ia(t_list **list, int *row)
{
  t_choice	hard;

  mk_clear();
  my_show_list(*list);
  my_putstr("Hardbot is loading its tactic\n");
  usleep(2000000);
  if (*row == 1)
    one_line(*list, &hard);
  else if (*row == 2)
    two_lines(list, &hard);
  else if (*row > 2)
    classic_move(list, &hard);
  change_line(list, &hard, row);
  if (end_game(*list, "Hard_bot") == 0)
    return (0);
  return (1);
}
