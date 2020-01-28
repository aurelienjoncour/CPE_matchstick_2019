/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** gameboard
*/

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
        my_putchar('*');
    my_putchar('\n');
}

static void display_nb_char(int nb, char c)
{
    for (int i = 0; i < nb; i++)
        my_putchar(c);
}

void display_gameboard(int *game_board, int nb_lines)
{
    int line_len = 1;
    int nb_space_right;
    int nb_space_left;

    for (int i = 0; i < nb_lines - 1; i++)
        line_len += 2;
    display_full_line(line_len + 2);
    for (int i = 0; i  < nb_lines; i++) {
        my_putchar('*');
        nb_space_left = nb_lines - (i + 1);
        display_nb_char(nb_space_left, ' ');
        display_nb_char(game_board[i], '|');
        nb_space_right = line_len - nb_space_left - game_board[i];
        display_nb_char(nb_space_right, ' ');
        my_putstr("*\n");
    }
    display_full_line(line_len + 2);
}

void game_action_msg(char *player, int line, int rm_matches)
{
    my_putstr(player);
    my_putstr(" removed ");
    my_put_nbr(rm_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putstr("\n");
}