/*
** boyard.c for allum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 16:35:44 2015 Antoine Zanardi
** Last update Tue Feb 10 15:00:55 2015 Antoine Zanardi
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"
#include	"allum1.h"

void		boyard_rules(int diff)
{
  mk_clear();
  my_putstr("20 allumettes sont alignés sur la table, vous pouvez");
  my_putstr(" prendre 1 à 3 allumettes.");
  my_putstr(" Celui qui prend la dernière a perdu.\n");
  if (diff == 2)
    my_putstr("Dans ce mode expert, le Maitre commence..\n");
  usleep(4000000);
  my_putstr("Maitre des ténèbres, je demande le jeu !\n");
  usleep(2500000);
}

void		display_allum(unsigned int allum)
{
  unsigned int	compt_allum;

  compt_allum = 0;
  while (compt_allum < allum)
    {
      my_putchar('|');
      compt_allum++;
    }
  my_putchar('\n');
}

void		player_choice(unsigned int *allum, int *choice)
{
  char		*nb_str;
  int		bool;

  bool = 0;
  while (bool == 0)
    {
      my_putstr("Combien d'allumettes voulez-vous retirer ?\n");
      if ((nb_str = get_next_line(0)) == NULL)
	exit(1);
      if (str_is_posi(nb_str) == 0 && str_is_ot(nb_str, *allum) == 0 &&
	  my_strlen(nb_str) < 2)
	bool = 1;
    }
  *choice = my_getnbr(nb_str);
  *allum = *allum - my_getnbr(nb_str);
}

int		boyard_end(char *str, int allum)
{
  if (allum == 1)
    {
      mk_clear();
      my_putstr("|\n");
      my_putstr(str);
      my_putstr(" a gagné !\n");
      return (0);
    }
  return (1);
}

void		game_boyard(int diff)
{
  unsigned int	allum;
  int		choice;

  boyard_rules(diff);
  allum = 20;
  while (allum != 1)
    {
      if (diff == 1)
	{
	  player_boyard(&allum, &choice);
	  if (boyard_end("Joueur 1", allum) == 0)
	    return;
	  ia_boyard(&allum, choice);
	}
      else if (diff == 2)
	{
	  if (ia_exp_boyard(&allum, choice) == 0)
	    return;
	  player_boyard(&allum, &choice);
	  if (boyard_end("Joueur 1", allum) == 0)
	    return;
	}
    }
}
