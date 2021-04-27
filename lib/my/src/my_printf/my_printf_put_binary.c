/*
** EPITECH PROJECT, 2020
** my_void_putstr
** File description:
** Source code
*/
#include <my.h>
#include <my/io.h>
#include <my/utils/printf_utils.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static int put_binary(fd_t fd, unsigned long long value)
{
    int len = 0;

    if (value > 2)
        len += put_binary(fd, value / 2);
    len += my_fd_putchar(fd, (value % 2) + '0');
    return (len);
}

int my_printf_put_binary(va_list *ap, printf_flag_parameters_t params)
{
    unsigned long long value = converted_va_arg_unsigned_nbr(ap, params);

    if (params.precision != -1)
        return (-2);
    return (put_binary(params.fd, value));
}