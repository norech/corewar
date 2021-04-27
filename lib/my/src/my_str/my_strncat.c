/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Append a string to another
*/
#include <my.h>

mut_str_t my_strncat(mut_str_t dest, str_t src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';

    return (dest);
}
