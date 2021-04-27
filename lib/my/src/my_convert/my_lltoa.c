/*
** EPITECH PROJECT, 2020
** my_lltoa
** File description:
** Puts a number
*/
#include <unistd.h>
#include <my.h>
#include <stdbool.h>

int my_lltoa(char *output, long long nb, int radix)
{
    char const *base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    bool is_negative = false;

    if (radix < 2 || radix > 36)
        return (-1);
    if (nb < 0)
        is_negative = true;
    else
        nb = -nb;
    while (-nb >= radix) {
        output[i++] = base[-nb % radix];
        nb /= radix;
    }
    output[i++] = base[-nb % radix];
    if (is_negative)
        output[i++] = '-';
    output[i] = '\0';
    my_revstr(output);
    return (i);
}
