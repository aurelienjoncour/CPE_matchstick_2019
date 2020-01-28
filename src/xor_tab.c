/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** xor_tab
*/

void tab_cpy(int *tab_src, int *tab_cpy, int nb_lines)
{
    for (int i = 0; i < nb_lines; i++)
        tab_cpy[i] = tab_src[i];
}

int xor_tab(int *tab, int nb_lines)
{
    int x = tab[0] ^ tab[1];

    for (int i = 2; i < nb_lines; i++)
        x = x ^ tab[i];
    return x;
}