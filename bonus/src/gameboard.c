/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** gameboard
*/

#include <ncurses.h>
#include "my.h"

void generate_gameboard(int *game_board, int nb_lines)
{
    int stick = 1;

    for (int i = 0; i < nb_lines; i++) {
        game_board[i] = stick;
        stick += 2;
    }
}

static void display_full_line(int line_len)
{
    for (int i = 0; i < line_len; i++)
        printw("*");
    printw("\n");
}

static void display_nb_char(int nb, char c)
{
    for (int i = 0; i < nb; i++)
        printw("%c", c);
}

void display_gameboard(int *game_board, int nb_lines)
{
    int line_len = 1;
    int nb_space_right;
    int nb_space_left;

    clear();
    for (int i = 0; i < nb_lines - 1; i++)
        line_len += 2;
    display_full_line(line_len + 2);
    for (int i = 0; i  < nb_lines; i++) {
        printw("*");
        nb_space_left = nb_lines - (i + 1);
        display_nb_char(nb_space_left, ' ');
        display_nb_char(game_board[i], '|');
        nb_space_right = line_len - nb_space_left - game_board[i];
        display_nb_char(nb_space_right, ' ');
        printw("*\n");
    }
    display_full_line(line_len + 2);
    refresh();
}

void game_action_msg(char *player, int line, int rm_matches)
{
    printw(player);
    printw(" removed ");
    printw("%d", rm_matches);
    printw(" match(es) from line ");
    printw("%d", line);
    printw("\n");
    refresh();
}