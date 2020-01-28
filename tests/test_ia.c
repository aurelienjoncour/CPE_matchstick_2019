/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_ia
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ia_matchstick.h"

Test(ia, win_ia)
{
    int game_board[] = {1, 1, 3, 0};
    int game_win[] = {1, 1, 1, 0};

    ia_play(4, game_board, 5);
    cr_assert_arr_eq(game_board, game_win, 4);
}

Test(ia, no_xor_solution)
{
    int game_board[] = {1, 1, 1, 0};
    int game_win[] =  {0, 1, 1, 0};

    ia_play(4, game_board, 5);
    cr_assert_arr_eq(game_board, game_win, 4);
}