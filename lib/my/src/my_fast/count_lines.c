/*
** EPITECH PROJECT, 2021
** count_lines
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>

size_t count_lines(char *str, bool ignore_trailing_line)
{
    size_t count = 1;
    size_t i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            if (str[i + 1] == '\0' && ignore_trailing_line)
                break;
            count++;
        }
    }
    return (count);
}