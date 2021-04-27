/*
** EPITECH PROJECT, 2020
** my_round_float
** File description:
** Round a floating number
*/
#include <my.h>
#include <stdio.h>

static int simplified_pow(int nb, int p)
{
    if (p == 0)
        return (1);
    int result = simplified_pow(nb, p - 1);
    return (result * nb);
}

float my_round_float(float nb, int digits)
{
    int power = simplified_pow(10, digits + 1);
    int decimals = (int)((nb - (int)nb) * power);
    float nb_cut = (int)nb;

    if ((decimals % 10) >= 5) {
        if (digits == 0)
            nb_cut += 1.0;
        else
            decimals += 10;
    }

    return (nb_cut + ((float)decimals / power));
}
