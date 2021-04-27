/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** Finds the nearest superior prime number
*/
#include <my.h>

int my_find_prime_sup(int nb)
{
    int i = nb;
    while (1) {
        if (my_is_prime(i))
            return (i);
        i++;
    }
}
