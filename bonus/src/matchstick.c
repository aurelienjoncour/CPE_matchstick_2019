/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** matchstick
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
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

static void start_game(int *game_board, int nb_lines)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    display_gameboard(game_board, nb_lines);
}

void end_game(void)
{
    refresh();
    sleep(2);
    endwin();
}

int matchstick(int nb_lines, int max_rm_matches, int *game_board)
{
    start_game(game_board, nb_lines);
    while (!check_end_game(game_board, nb_lines)) {
        printw("\nYour turn:\n");
        if (!game_request(nb_lines, max_rm_matches, game_board)) {
            endwin();
            return 0;
        }
        display_gameboard(game_board, nb_lines);
        if (check_end_game(game_board, nb_lines)) {
            printw("You lost, too bad...\n");
            end_game();
            return 2;
        }
        printw("\nAI's turn...\n");
        ia_play(nb_lines, game_board, max_rm_matches);
        display_gameboard(game_board, nb_lines);
    }
    printw("I lost... snif... but I'll get you next time!\n");
    end_game();
    return 1;
}