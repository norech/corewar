/*
** EPITECH PROJECT, 2020
** my_io
** File description:
** Source code
*/

#ifndef MY_IO_H
#define MY_IO_H

#include <my/types.h>

int my_printf(const char *s, ...);

int my_dprintf(fd_t fd, char *s, ...);

int my_fd_put_digit(fd_t fd, int i);

int my_fd_putchar(fd_t fd, char c);

int my_fd_putstr(fd_t fd, char const *str);

int my_fd_put_float(fd_t fd, float nb, int digits);

int my_fd_put_nbr_base(fd_t fd, long long nb, int radix);

int my_fd_put_nbr(fd_t fd, long long nb);

int my_fd_put_u_nbr(fd_t fd, unsigned long long nb);

#ifndef STDOUT_FILENO
    #define STDIN_FILENO  0
    #define STDOUT_FILENO 1
    #define STDERR_FILENO 2
#endif

#endif //MY_IO_H
