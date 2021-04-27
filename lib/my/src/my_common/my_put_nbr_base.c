/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <my.h>

int my_put_nbr_base(long long nb, int radix)
{
    int len = 0;

    if (radix < 2)
        return (-1);
    if (nb < 0) {
        len += my_putchar('-');
        nb *= -1;
    }
    if (nb >= radix)
        len += my_put_nbr_base(nb / radix, radix);
    len += my_put_digit(nb % radix);
    return (len);
}
