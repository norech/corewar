/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Get the length of a string
*/
#include <my.h>

int my_strlen(str_t str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return (i);

}
