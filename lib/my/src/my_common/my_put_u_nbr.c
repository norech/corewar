/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <my.h>

int my_put_u_nbr(unsigned long long nb)
{
    int len = 0;

    if (nb >= 10)
        len += my_put_u_nbr(nb / 10);
    len += my_put_digit(nb % 10);
    return (len);
}