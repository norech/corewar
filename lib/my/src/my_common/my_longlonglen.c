/*
** EPITECH PROJECT, 2020
** my_numlen
** File description:
** Get length of a number
*/
#include <my.h>

int my_longlonglen(long long number, int radix)
{
    int length = 0;

    if (radix < 2)
        return (-1);
    if (number < 0) {
        length++;
        number = -number;
    }
    while (number >= radix) {
        length++;
        number /= radix;
    }
    length++;
    return (length);
}
