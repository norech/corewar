/*
** EPITECH PROJECT, 2020
** my_ltoa
** File description:
** Puts a number
*/
#include <unistd.h>
#include <my.h>

int my_uitoa(char *output, unsigned int nb, int radix)
{
    char const *base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;

    if (radix < 2 || radix > 36)
        return (-1);
    while (nb >= (unsigned int)radix) {
        output[i++] = base[nb % radix];
        nb /= radix;
    }
    output[i++] = base[nb % radix];
    output[i] = '\0';
    my_revstr(output);
    return (i);
}