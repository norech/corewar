/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Computes power recursively
*/
#include <my.h>

static int may_overflow_if_multiplied(int number, int digit)
{
    return (number > 2147483647 - (number * (digit - 1)));
}

int my_pow(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    int result = my_pow(nb, p - 1);
    if (may_overflow_if_multiplied(result, nb))
        return (0);
    return (result * nb);
}
