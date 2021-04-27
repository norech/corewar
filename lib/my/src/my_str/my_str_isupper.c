/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** Check if string is uppercase
*/
#include <my.h>

bool my_str_isupper(str_t str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_char_lowercase(str[i]))
            return (false);
        i++;
    }

    return (true);
}
