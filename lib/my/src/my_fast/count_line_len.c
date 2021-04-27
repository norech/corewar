/*
** EPITECH PROJECT, 2021
** count_line_len
** File description:
** Source code
*/

#include <my.h>

size_t count_line_len(char *str)
{
    size_t i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}