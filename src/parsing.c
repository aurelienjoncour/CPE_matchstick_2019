/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** parsing
*/

#include "my.h"

int parsing_number(char *str)
{
    if (!my_str_isnum(str) || my_strlen(str) == 0)
        return -1;
    else
        return my_getnbr(str);
}