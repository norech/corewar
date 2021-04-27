/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** Check if string is lowercase
*/
#include <my.h>

bool my_str_islower(str_t str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_char_uppercase(str[i]))
            return (false);
        i++;
    }
    return (true);
}
