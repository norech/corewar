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

int my_printf_putstr_printable(va_list *ap, printf_flag_parameters_t params)
{
    char *value = va_arg(*ap, char *);

    if (params.precision != -1)
        return (-2);
    while (*value != '\0') {
        if (*value >= 32 && *value < 127) {
            my_fd_putchar(params.fd, *value);
            value++;
            continue;
        }
        my_fd_putchar(params.fd, '\\');
        int len = my_intlen(*value, 8);
        while ((len++) < 3)
            my_fd_put_digit(params.fd, 0);
        my_fd_put_nbr_base(params.fd, *value, 8);
        value++;
    }
    return (0);
}