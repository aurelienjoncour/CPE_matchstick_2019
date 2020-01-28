##
## EPITECH PROJECT, 2020
## CPE_matchstick_2019
## File description:
## Makefile
##

SRC_DIR		=	../src/
INC_DIR		=	../include/
LIB_DIR		=	../lib/my

SRC		=	$(SRC_DIR)gameboard.c				\
			$(SRC_DIR)ia_matchstick.c			\
			$(SRC_DIR)parsing.c					\
			$(SRC_DIR)xor_tab.c					\
			$(SRC_DIR)get_next_line.c			\
			test_gameboard.c					\
			test_gnl.c							\
			test_ia.c							\
			test_parsing.c						\
			test_xortab.c						\

OBJ		=	$(SRC:.c=.o)

NAME		=	test

CFLAGS		+=	-Wall -Wextra --coverage -I $(INC_DIR)

LDFLAGS		=	-L $(LIB_DIR) -lmy --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR) --no-print-directory
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)
clean:
		rm -f $(OBJ)
		rm -f $(OBJ:.o=.gcno)
		rm -f $(OBJ:.o=.gcda)

fclean:		clean
			rm	-f	$(NAME)

re:		fclean all