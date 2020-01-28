/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_gnl
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

Test(gnl, read_one_line)
{
    int fd = open("test_gnl.c", O_RDONLY);
    char *str;

    if (fd != -1)
        str = get_next_line(fd);
    cr_assert_str_eq(str, "/*");
    free(str);
    str = get_next_line(fd);
    cr_assert_str_eq(str, "** EPITECH PROJECT, 2020");
    free(str);
    close(fd);
}