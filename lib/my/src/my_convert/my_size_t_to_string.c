/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <unistd.h>
#include <my.h>
#include <stdbool.h>

int my_size_t_to_string(char *output, size_t nb, int radix)
{
    char const *base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;

    if (radix < 2 || radix > 36)
        return (-1);
    while (nb >= (size_t)radix) {
        output[i++] = base[nb % radix];
        nb /= radix;
    }
    output[i++] = base[nb % radix];
    output[i] = '\0';
    my_revstr(output);
    return (i);
}