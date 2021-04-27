/*
** EPITECH PROJECT, 2020
** my_strpad
** File description:
** Source code
*/
#include <my.h>
#include <my/types.h>
#include <stdlib.h>
#include <stdio.h>

mut_str_t my_strpad_start(mut_str_t dest, char pattern, int size)
{
    int dest_len = my_strlen(dest);
    char tmp[dest_len];
    int i = 0;
    int fill_len = size - dest_len;

    my_strcpy(tmp, dest);
    if (fill_len > 0) {
        while (i < fill_len) {
            dest[i] = pattern;
            i++;
        }
    }
    dest[i] = '\0';
    my_strncat(dest, tmp, dest_len);
    if (size < dest_len)
        dest[size] = '\0';
    return (dest);
}