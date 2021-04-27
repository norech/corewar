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

int my_printf_putchar(va_list *ap, printf_flag_parameters_t params)
{
    char value = va_arg(*ap, int);

    if (params.precision != -1)
        return (-2);
    return (my_fd_putchar(params.fd, value));
}