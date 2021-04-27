/*
** EPITECH PROJECT, 2020
** my_str_filter
** File description:
** Filters characters out of a string
*/
#include <my.h>

void my_str_filter(char *str, int (*filter)(int i, char c))
{
    int len = my_strlen(str);
    char copy[len + 1];
    int i = 0;
    int j = 0;

    my_strcpy(copy, str);
    my_bzero(str, len + 1);
    while (copy[i] != '\0') {
        if (!(*filter)(i, str[i])) {
            str[j] = copy[i];
            j++;
        }
        i++;
    }
}