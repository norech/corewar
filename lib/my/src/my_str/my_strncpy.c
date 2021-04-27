/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Copy one string to another
*/
#include <my.h>

mut_str_t my_strncpy(mut_str_t dest, str_t src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i <= n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
