/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <my.h>

int my_put_nbr(long long nb)
{
    int len = 0;

    if (nb < 0) {
        len += my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10)
        len += my_put_nbr(nb / 10);
    len += my_put_digit(nb % 10);
    return (len);
}