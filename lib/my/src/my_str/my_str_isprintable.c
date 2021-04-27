/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** Check if string is printable
*/
#include <my.h>

bool my_str_isprintable(str_t str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_char_printable(str[i]))
            return (false);
        i++;
    }

    return (true);
}
