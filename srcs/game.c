/*
** game.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 10:42:08 2015 Antoine Zanardi
** Last update Sat Feb 21 16:29:49 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"
#include	"allum1.h"

void		row_choice(int *row, t_choice *choice)
{
  char		*row_str;
  int		bool_row;

  bool_row = 0;
  while (bool_row == 0)
    {
      my_putstr("On which line do you want to pick matchsticks?\n");
      if ((row_str = get_next_line(0)) == NULL)
	exit(1);
      if (str_is_posi(row_str) == 0 && compare_nb(row_str, *row) == 0 &&
	  my_strlen(row_str) < 3)
	bool_row = 1;
    }
  choice->row = my_getnbr(row_str);
}

void		match_choice(t_list **list, t_choice *choice)
{
  char		*stick_str;
  int		bool_stick;
  int		compt_row;
  t_list	*tmp;

  tmp = *list;
  compt_row = 1;
  while (compt_row < choice->row)
    {
      tmp = tmp->next;
      compt_row++;
    }
  bool_stick = 0;
  while (bool_stick == 0)
    {
      my_putstr("How many matchsticks do you want to pick up?\n");
      if ((stick_str = get_next_line(0)) == NULL)
	exit(1);
      if (str_is_posi(stick_str) == 0 &&
	  compare_a(stick_str, tmp->nombre, *list) == 0 &&
	  my_strlen(stick_str) < 3)
	bool_stick = 1;
    }
  choice->number = my_getnbr(stick_str);
}

void		player_mari(t_list **list, int *row, t_choice *pl, char *str)
{
  mk_clear();
  my_show_list(*list);
  my_putstr(str);
  my_putstr(", ");
  row_choice(row, pl);
  match_choice(list, pl);
  change_line(list, pl, row);
}

void		game_multi(t_list **list, int *row)
{
  t_choice	player;

  player_mari(list, row, &player, "Player 1");
  if (end_game(*list, "Player 1") == 0)
    {
      free(*list);
      exit(0);
    }
  player_mari(list, row, &player, "Player 2");
  if (end_game(*list, "Player 2") == 0)
    {
      free(*list);
      exit(0);
    }
}

void		play_the_game(t_list **list, int *row, int difficulty)
{
  t_choice	player;

  if (difficulty == 1)
    {
      player_mari(list, row, &player, "Player 1");
      if (end_game(*list, "Player 1") == 0)
	return;
      if (easy_ia(list, row) == 0)
	return;
    }
  else if (difficulty == 2)
    {
      player_mari(list, row, &player, "Player 1");
      if (end_game(*list, "Player 1") == 0)
	return;
      if (hard_ia(list, row) == 0)
	return;
    }
}
