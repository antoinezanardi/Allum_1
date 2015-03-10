/*
** my_putstr.c for my_putstr in /home/zanard_a/rendu/J4/ex2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Oct  2 11:54:38 2014 Antoine Zanardi
** Last update Sat Feb 21 16:25:03 2015 Antoine Zanardi
*/

#include	"my.h"

void		my_putstr(char *str)
{
  int		c;

  c = 0;
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c++;
    }
}
