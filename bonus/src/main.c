/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "matchstick.h"
#include "gameboard.h"

int main(int ac, char **av)
{
    int nb_lines;
    int max_rm_matches;
    int *game_board;
    int game_status;

    if (ac != 3)
        return 84;
    nb_lines = my_getnbr(av[1]);
    max_rm_matches = my_getnbr(av[2]);
    if ((nb_lines < 2 || nb_lines > 99) || max_rm_matches < 1)
        return 84;
    game_board = malloc(sizeof(int) * nb_lines);
    if (game_board == NULL)
        return 84;
    generate_gameboard(game_board, nb_lines);
    game_status = matchstick(nb_lines, max_rm_matches, game_board);
    free(game_board);
    return game_status;
}