/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parsing.h"

Test(parsing, string_error)
{
    int i = parsing_number("ace");

    cr_assert_eq(i, -1);
}

Test(parsing, string_valid)
{
    int i = parsing_number("2");

    cr_assert_eq(i, 2);
}