/*
** EPITECH PROJECT, 2020
** my_strpad
** File description:
** Source code
*/
#include <my.h>
#include <my/types.h>

mut_str_t my_strpad_end(mut_str_t dest, char pattern, int size)
{
    int i = my_strlen(dest);
    if (i >= size) {
        dest[size] = '\0';
        return (dest);
    }
    while (i < size) {
        dest[i] = pattern;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}