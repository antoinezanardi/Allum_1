/*
** my_lists.c for my_lists in /home/zanard_a/rendu/Librairie/Librairie_off
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:19:28 2014 Antoine Zanardi
** Last update Sat Feb 21 16:24:25 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"allum1.h"
#include	"my.h"

int		add_top_list(t_list **list, unsigned int nombre)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (0);
  elem->nombre = nombre;
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int		add_bot_list(t_list **list, unsigned int nombre)
{
  t_list	*elem;
  t_list	*tmp;

  if ((*list) == NULL)
    return (add_top_list(list, nombre));
  elem = malloc(sizeof(t_list));
  if (elem == NULL)
    return (0);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->nombre = nombre;
  elem->next = NULL;
  elem->prev = tmp;
  tmp->next = elem;
  return (0);
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;
  unsigned int	nb;
  unsigned int	compt_space;

  tmp = list;
  while (tmp != NULL)
    {
      nb = 0;
      compt_space = 0;
      while ((bigger_line(&list) - tmp->nombre) / 2 > compt_space)
	{
	  my_putchar(' ');
	  compt_space++;
	}
      while (nb < tmp->nombre)
	{
	  my_putchar('|');
	  nb++;
	}
      my_putchar('\n');
      tmp = tmp->next;
    }
  my_putchar('\n');
}
