/*
** EPITECH PROJECT, 2020
** my_numlen
** File description:
** Get length of a number
*/
#include <my.h>
#include <unistd.h>

int my_size_t_len(size_t number, int radix)
{
    int length = 0;

    if (radix < 2)
        return (-1);
    while (number >= (size_t)radix) {
        length++;
        number /= radix;
    }
    length++;
    return (length);
}
