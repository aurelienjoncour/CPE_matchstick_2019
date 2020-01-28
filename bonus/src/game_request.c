/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** game_request
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include "my.h"
#include "gameboard.h"
#include "get_line_and_matches.h"

void erase_actual_line(void)
{
    int x = 0;
    int y = 0;

    getyx(stdscr, y , x);
    move(y, 0);
    clrtoeol();
    (void)x;
}

int game_request(int nb_lines, int max_rm_matches, int *game_board)
{
    int line = 0;
    int rm_matches = 0;
    bool a = true;

    while (a) {
        line = 0;
        rm_matches = 0;
        if (!get_nbr_line(&line, nb_lines))
            return 0;
        rm_matches = get_nbr_matches();
        a = error_nbr_matches(line, rm_matches, max_rm_matches, game_board);
    }
    game_board[line - 1] -= rm_matches;
    game_action_msg("Player", line, rm_matches);
    sleep(1);
    return 1;
}