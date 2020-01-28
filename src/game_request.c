/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** game_request
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "get_next_line.h"
#include "gameboard.h"
#include "parsing.h"

static int get_nbr_line(int *line, int nb_lines)
{
    char *str;

    while (*line < 1 || *line > nb_lines) {
        my_putstr("Line: ");
        str = get_next_line(0);
        if (str == NULL)
            return 0;
        *line = parsing_number(str);
        if (*line < 0)
            my_putstr("Error: invalid input (positive number expected)\n");
        if (*line == 0 || *line > nb_lines)
            my_putstr("Error: this line is out of range\n");
        free(str);
    }
    return 1;
}

static int error_nbr_matches(int line, int rm_matches, int max_rm_matches,
                            int *game_board)
{
    if (rm_matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return 1;
    }
    if (rm_matches < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 1;
    }
    if (rm_matches > max_rm_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(max_rm_matches);
        my_putstr(" matches per turn\n");
        return 1;
    }
    if (game_board[line - 1] < rm_matches) {
        my_putstr("Error: not enough matches on this line\n");
        return 1;
    }
    return 0;
}

static char *get_nbr_matches(void)
{
    char *str;

    my_putstr("Matches: ");
    str = get_next_line(0);
    if (str == NULL)
        return NULL;
    else
        return str;
}

int game_request(int nb_lines, int max_rm_matches, int *game_board)
{
    int line = 0;
    int rm_matches = 0;
    char *nbr;
    bool a = true;

    while (a) {
        line = 0;
        rm_matches = 0;
        if (!get_nbr_line(&line, nb_lines))
            return 0;
        nbr = get_nbr_matches();
        if (nbr == NULL)
            return 0;
        rm_matches = parsing_number(nbr);
        a = error_nbr_matches(line, rm_matches, max_rm_matches, game_board);
        free(nbr);
    }
    game_board[line - 1] -= rm_matches;
    game_action_msg("Player", line, rm_matches);
    return 1;
}