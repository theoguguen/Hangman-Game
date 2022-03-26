##
## EPITECH PROJECT, 2021
## Pendu
## File description:
## Makefile
##

SRCDIR	=	src

SRC	=	$(SRCDIR)/main.c		\
		$(SRCDIR)/help.c		\
		$(SRCDIR)/pendu.c		\
		$(SRCDIR)/end_game.c	\
		$(SRCDIR)/init.c		\
		$(SRCDIR)/print.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I includes/

NAME	=	hangman

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug:	CFLAGS += -g
debug:	re

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all