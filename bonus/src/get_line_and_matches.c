/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** get_line_and_matches
*/

#include <ncurses.h>
#include "game_request.h"

static void write_line_error_msg(int line, int nb_lines)
{
    if (line < 0) {
        printw("Error: invalid input (positive number expected)\n");
        refresh();
    }
    if (line == 0 || line > nb_lines) {
        printw("Error: this line is out of range\n");
        refresh();
    }
}

static void increment_nb_lines(int i, int *line)
{
    if (i == KEY_UP)
        *line = *line + 1;
    if (i == KEY_DOWN)
        *line = *line - 1;
}

int get_nbr_line(int *line, int nb_lines)
{
    int i = 0;
    int tab[2] = {0};

    while (*line < 1 || *line > nb_lines) {
        while (1) {
            erase_actual_line();
            printw("Line: %d", *line);
            refresh();
            i = getch();
            increment_nb_lines(i, line);
            if (i == 10)
                break;
            if (i == 32)
                return 0;
        }
        write_line_error_msg(*line, nb_lines);
    }
    getyx(stdscr, tab[1], tab[0]);
    move(tab[1]+1, 0);
    return 1;
}

int error_nbr_matches(int line, int rm_matches, int max_rm_matches,
                            int *game_board)
{
    if (rm_matches == 0) {
        printw("Error: you have to remove at least one match\n");
        return 1;
    }
    if (rm_matches < 0) {
        printw("Error: invalid input (positive number expected)\n");
        return 1;
    }
    if (rm_matches > max_rm_matches) {
        printw("Error: you cannot remove more than ");
        printw("%d  matches per turn\n", max_rm_matches);
        return 1;
    }
    if (game_board[line - 1] < rm_matches) {
        printw("Error: not enough matches on this line\n");
        return 1;
    }
    return 0;
}

int get_nbr_matches(void)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int matches = 0;

    while (1) {
        printw("Matches: %d", matches);
        refresh();
        i = getch();
        if (i == KEY_UP)
            matches++;
        if (i == KEY_DOWN)
            matches--;
        if (i == 10)
            break;
        if (i == 32)
            return 0;
        erase_actual_line();
    }
    return matches;
}