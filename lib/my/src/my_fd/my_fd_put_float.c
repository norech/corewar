/*
** EPITECH PROJECT, 2020
** my_put_float
** File description:
** Print a floating number
*/
#include <my.h>
#include <my/io.h>

static int simplified_pow(int nb, int p)
{
    if (p == 0)
        return (1);
    int result = simplified_pow(nb, p - 1);
    return (result * nb);
}

int my_fd_put_float(fd_t fd, float nb, int digits)
{
    int len = 0;
    int power = simplified_pow(10, digits);
    int decimals = (int)((nb - (int)nb) * power);
    int zeros_count = digits - my_numlen(decimals);
    int i = 0;

    my_put_nbr((int) nb);
    if (digits > 0) {
        len += my_fd_putchar(fd, '.');
        while (i < zeros_count) {
            len += my_fd_put_digit(fd, 0);
            i++;
        }
        len += my_fd_put_nbr(fd, decimals);
    }
    return (len);
}
