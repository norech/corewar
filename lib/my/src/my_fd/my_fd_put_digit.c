/*
** EPITECH PROJECT, 2020
** my_put_digit
** File description:
** Print a digit in any base
*/
#include <my/io.h>
#include <my.h>

int my_fd_put_digit(int fd, int i)
{
    return (my_fd_putchar(fd, my_get_digit_char(i)));
}
