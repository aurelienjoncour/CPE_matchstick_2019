/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_gameboard
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "gameboard.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (display_gameboard, simple, .init = redirect_all_std)
{
    int tab[] = {1, 3, 5, 7};
    char s1[50] = "*********\n*   |   *\n*  |||  *\n";
    char s2[50] = "* ||||| *\n*|||||||*\n*********\n";

    strcat(s1, s2);
    display_gameboard(tab, 4);
    cr_assert_stdout_eq_str(s1);
}

Test (generate_gameboard, simple)
{
    int tab_src[] = {1, 3, 5, 7};
    int tab_dest[4] = {0};

    generate_gameboard(tab_dest, 4);

    cr_assert_arr_eq(tab_src, tab_dest, 4);
}

Test (game_action_msg, player, .init = redirect_all_std)
{
    game_action_msg("Player", 1, 1);
    cr_assert_stdout_eq_str("Player removed 1 match(es) from line 1\n");
}
