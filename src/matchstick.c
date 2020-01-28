/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** matchstick
*/

#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"
#include "my.h"
#include "gameboard.h"
#include "ia_matchstick.h"
#include "game_request.h"

static bool check_end_game(int *game_board, int nb_lines)
{
    for (int i = 0; i < nb_lines; i++)
        if (game_board[i] > 0)
            return false;
    return true;
}

int matchstick(int nb_lines, int max_rm_matches, int *game_board)
{
    display_gameboard(game_board, nb_lines);
    while (!check_end_game(game_board, nb_lines)) {
        my_putstr("\nYour turn:\n");
        if (!game_request(nb_lines, max_rm_matches, game_board))
            return 0;
        display_gameboard(game_board, nb_lines);
        if (check_end_game(game_board, nb_lines)) {
            my_putstr("You lost, too bad...\n");
            return 2;
        }
        my_putstr("\nAI's turn...\n");
        ia_play(nb_lines, game_board, max_rm_matches);
        display_gameboard(game_board, nb_lines);
    }
    my_putstr("I lost... snif... but I'll get you next time!\n");
    return 1;
}