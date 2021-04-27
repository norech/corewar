/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <my.h>
#include <my/io.h>

int my_fd_put_nbr_base(fd_t fd, long long nb, int radix)
{
    int len = 0;

    if (radix < 2)
        return (-1);
    if (nb < 0) {
        len += my_fd_putchar(fd, '-');
        nb *= -1;
    }
    if (nb >= radix)
        len += my_fd_put_nbr_base(fd, nb / radix, radix);
    len += my_fd_put_digit(fd, nb % radix);
    return (len);
}
