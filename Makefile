##
## Makefile for make in /home/zanard_a/rendu/Projets Piscines/expr
##
## Made by Antoine Zanardi
## Login   <zanard_a@epitech.net>
##
## Started on  Tue Oct 21 16:47:57 2014 Antoine Zanardi
## Last update Tue Feb 10 18:34:36 2015 Antoine Zanardi
##

DEBUG	=	no

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wall -Wextra
endif

LIB_PA	=	./lib/my/

NAME	=	allum1

SRCS_PA =	./srcs/

SRCS	=	$(SRCS_PA)main.c \
		$(SRCS_PA)list.c \
		$(SRCS_PA)fc.c \
		$(SRCS_PA)get_next_line.c \
		$(SRCS_PA)error.c \
		$(SRCS_PA)game.c \
		$(SRCS_PA)term.c \
		$(SRCS_PA)easy_ia.c \
		$(SRCS_PA)boyard.c \
		$(SRCS_PA)fc_boyard.c \
		$(SRCS_PA)ia_boyard.c \
		$(SRCS_PA)ia_exp_boyard.c \
		$(SRCS_PA)hard_ia.c \

SRCS_LI	=	$(LIB_PA)my_getnbr.c \
		$(LIB_PA)my_putchar.c \
		$(LIB_PA)my_put_nbr.c \
		$(LIB_PA)my_putstr.c \
		$(LIB_PA)my_strlen.c \
		$(LIB_PA)my_lists.c \

OBJS	=	$(SRCS:.c=.o)

OBJS_LI	=	$(SRCS_LI:.c=.o)

INC	=	-I include/

LIB_CMP	=	$(LIB_PA)libmy.a

CFLAGS	+=	$(INC)


all: $(LIB_CMP) $(NAME)

$(LIB_CMP): $(OBJS_LI)
	ar rc $(LIB_CMP) $(OBJS_LI)
	ranlib $(LIB_CMP)
	cp $(LIB_PA)my.h ./include/

$(NAME): $(OBJS)
	cc -Wall $(OBJS) lib/my/libmy.a -lncurses $(MLX) $(INC) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_LI)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_CMP)

re: fclean all

.PHONY: all clean fclean all
