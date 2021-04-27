/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** Check if string is alphabetic
*/
#include <my.h>

bool my_str_isalpha(str_t str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_char_alpha(str[i]))
            return (false);
        i++;
    }
    return (true);
}
