/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two string
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;

    dest[i] = 0;
    while (j < my_strlen(src)) {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}