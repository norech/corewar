/*
** EPITECH PROJECT, 2020
** my_void_putpercent
** File description:
** Source code
*/
#include <my.h>
#include <my/io.h>
#include <my/utils/printf_utils.h>
#include <stdarg.h>

int my_printf_put_percent(va_list *ap UNUSED, printf_flag_parameters_t params)
{
    if (params.precision != -1)
        return (-2);
    return (my_fd_putchar(params.fd, '%'));
}