/*
** main.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 09:32:02 2015 Antoine Zanardi
** Last update Sat Feb 21 16:29:47 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"
#include	"allum1.h"

void		choose_difficulty(int *diff)
{
  char		*diff_str;
  int		bool;

  bool = 0;
  while (bool == 0)
    {
      mk_clear();
      my_putstr("Quel est le niveau de l'IA? 1-> Normal / 2-> Expert\n");
      if ((diff_str = get_next_line(0)) == NULL)
	exit(1);
      if (str_is_mode(diff_str) == 0)
	bool = 1;
    }
  *diff = my_getnbr(diff_str);
}

void		choose_mode(int *mode)
{
  char		*mode_str;
  int		bool_mode;

  bool_mode = 0;
  while (bool_mode == 0)
    {
      mk_clear();
      my_putstr("Which game do you want to play? 1-> Marienbad / 2-> Boyard\n");
      if ((mode_str = get_next_line(0)) == NULL)
	exit(1);
      else if (str_is_mode(mode_str) == 0 && my_strlen(mode_str) < 2)
	bool_mode = 1;
    }
  *mode = my_getnbr(mode_str);
}

void		make_rules(int *row)
{
  char		*row_str;
  int		bool_row;

  bool_row = 0;
  while (bool_row == 0)
    {
      mk_clear();
      my_putstr("How many lines do you want in the game? (99 max)\n");
      if ((row_str = get_next_line(0)) == NULL)
	exit(1);
      else if (str_is_posi(row_str) == 0 && my_strlen(row_str) < 3)
	bool_row = 1;
    }
  if ((*row = my_getnbr(row_str)) <= 2)
    my_putstr_error(1);
}

void		is_multi(int *multiplayer)
{
  char		*multi_str;
  int		bool;

  bool = 0;
  while (bool == 0)
    {
      mk_clear();
      my_putstr("Do you have a friend to play with ? 1-> No / 2-> YES\n");
      if ((multi_str = get_next_line(0)) == NULL)
	exit(1);
      if (str_is_mode(multi_str) == 0 && my_strlen(multi_str) < 3)
	bool = 1;
    }
  *multiplayer = my_getnbr(multi_str);
}

int		main(void)
{
  t_list	*list;
  t_param	param;
  int		row;

  list = NULL;
  choose_mode(&(param.mode));
  if (param.mode == 1)
    {
      make_rules(&row);
      fill_my_list(&list, row);
      is_multi(&(param.multiplayer));
      if (param.multiplayer == 2)
	while (list->next != NULL || list->prev != NULL || list->nombre != 1)
	  game_multi(&list, &row);
      choose_difficulty(&(param.difficulty));
      while (list->next != NULL || list->prev != NULL || list->nombre != 1)
	play_the_game(&list, &row, param.difficulty);
    }
  else if (param.mode == 2)
    {
      choose_difficulty(&(param.difficulty));
      game_boyard(param.difficulty);
    }
  free(list);
  return (0);
}
