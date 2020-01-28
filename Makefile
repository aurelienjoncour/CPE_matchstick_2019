##
## EPITECH PROJECT, 2020
## PSU_my_ls_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c			\
				$(SRC_DIR)get_next_line.c	\
				$(SRC_DIR)gameboard.c		\
				$(SRC_DIR)matchstick.c		\
				$(SRC_DIR)ia_matchstick.c	\
				$(SRC_DIR)game_request.c	\
				$(SRC_DIR)parsing.c			\
				$(SRC_DIR)xor_tab.c

OBJ			=	$(SRC:.c=.o)

NAME		=	matchstick

CFLAGS		+=	-Wall -Wextra -I./include -g

LDLFLAGS	+= -L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIB_DIR)
			gcc -o $(NAME) $(OBJ) $(LDLFLAGS)
			make clean

clean:
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(OBJ)

fclean:		clean
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

tests_run:	fclean
			make -C tests/

bonus:	fclean
		rm bonus_matchstick
		make -C bonus
		cp bonus/matchstick bonus_matchstick

debugs:	fclean all
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -g

.PHONY: all clean fclean re run debugs
