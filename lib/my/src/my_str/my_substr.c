/*
** EPITECH PROJECT, 2020
** my_substr
** File description:
** Returns a part of a string
*/
#include <my.h>

char *my_substr(char *str, int start, int end)
{
    int len = my_strlen(str);

    if (start < 0)
        start = len + start;
    if (end < 0)
        end = len + end;
    if (start > end || end < 0 || start < 0 || start > len || end > len)
        return (NULL);
    return (my_strndup(str + start, end - start));
}