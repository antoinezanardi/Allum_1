/*
** term.c for alum1 in /home/zanard_a/rendu/Projets_TEK1/Allum1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  9 14:01:47 2015 Antoine Zanardi
** Last update Sat Feb 21 16:44:56 2015 Antoine Zanardi
*/

#include	<ncurses/curses.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<term.h>
#include	"get_next_line.h"
#include	"my.h"
#include	"allum1.h"

int		put_in_term(int c)
{
  write(1, &c, 1);
  return (0);
}

int		mk_clear()
{
  char		*clean;

  if (tgetent(NULL, "xterm") != 1)
    {
      my_putstr("Error with xterm\n");
      exit(1);
    }
  if ((clean = tgetstr("cl", NULL)) == NULL)
    return (1);
  if (tputs(clean, 0, &put_in_term) <= 0)
    return (1);
  return (0);
}
