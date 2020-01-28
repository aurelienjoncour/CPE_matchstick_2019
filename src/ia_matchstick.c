/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia_matchstick
*/

#include <stdbool.h>
#include <stdlib.h>
#include "gameboard.h"
#include "xor_tab.h"

static void rm_one_matches(int nb_lines, int *game_board)
{
    int line = 0;

    for (int i = 0; i < nb_lines; i++)
        if (game_board[i] > 0) {
            line = i;
            break;
        }
    game_action_msg("AI", line + 1, 1);
    game_board[line] -= 1;
}

static int end_ia(int ia_lines, int ia_matches, int **game_board, int *copy_tab)
{
    game_action_msg("AI", ia_lines + 1, ia_matches);
    (*game_board)[ia_lines] -= ia_matches;
    free(copy_tab);
    return 0;
}

static int end_ia2(int nb_lines, int *game_board, int *copy_tab)
{
    rm_one_matches(nb_lines, game_board);
    free(copy_tab);
    return 1;
}

static bool check_xor(int *tab, int nb, int matches, int max_matches)
{
    if (xor_tab(tab, nb) == 1 && matches != 0 && matches < max_matches)
        return true;
    return false;
}

int ia_play(int nb_lines, int *game_board, int max_rm_matches)
{
    int *copy_tab = malloc(sizeof(int) * nb_lines);
    int ia_matches = 0;
    int ia_lines = 0;

    for (int i = 0; i < nb_lines; i++) {
        tab_cpy(game_board, copy_tab, nb_lines);
        ia_matches = 0;
        while (xor_tab(copy_tab, nb_lines) != 1 && copy_tab[i] != 0
                && ia_matches <= max_rm_matches) {
            ia_matches++;
            copy_tab[i] = game_board[i] - ia_matches;
        }
        if (check_xor(copy_tab, nb_lines, ia_matches, max_rm_matches)) {
            ia_lines = i;
            break;
        }
        else if (i == nb_lines - 1)
            return end_ia2(nb_lines, game_board, copy_tab);
    }
    return end_ia(ia_lines, ia_matches, &game_board, copy_tab);
}