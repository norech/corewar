/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** Computes square root
*/
#include <my.h>

int my_sqrt(int nb)
{
    int i = 0;
    if (nb == 0)
        return (0);
    while (i <= nb) {
        if ((i * i) == nb)
            return (i);
        i++;
    }
    return (0);
}
