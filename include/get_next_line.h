/*
** get_next_line.h for get_next_line in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_get_next_line
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Nov 17 11:52:13 2014 Antoine Zanardi
** Last update Mon Feb  9 14:03:24 2015 Antoine Zanardi
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_
# define	BUFFER_SIZE	4096

typedef struct	s_struct
{
  char		*str_tmp;
  char		*str;
  int		str_compt;
  int		boo;
  int		ret;
}		t_str;

char	*get_next_line(const int);
int	my_len(char *);
char	*str_paste(char *, char *);
int	check_my_entry(char *, int);

#endif /* !GET_NEXT_LINE_H_ */
