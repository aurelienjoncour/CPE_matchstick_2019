/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_xortab
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "xor_tab.h"

Test(xor, test_xor)
{
    int tab[] = {7, 5, 3, 1};

    cr_assert_eq(xor_tab(tab, 4), 7 ^ 5 ^ 3 ^ 1);
}

Test(tab_cpy, test_cpy)
{
    int tab_src[] = {7, 5, 3, 1};
    int tab_dest[4] = {0};

    tab_cpy(tab_src, tab_dest, 4);

    cr_assert_arr_eq(tab_src, tab_dest, 4);
}