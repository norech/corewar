/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Puts a number
*/
#include <my.h>
#include <my/io.h>

int my_fd_put_u_nbr(fd_t fd, unsigned long long nb)
{
    int len = 0;

    if (nb >= 10)
        len += my_fd_put_u_nbr(fd, nb / 10);
    len += my_fd_put_digit(fd, nb % 10);
    return (len);
}