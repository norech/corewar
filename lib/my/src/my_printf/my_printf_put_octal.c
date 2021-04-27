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

int my_printf_put_octal(va_list *ap, printf_flag_parameters_t params)
{
    unsigned long long value = converted_va_arg_unsigned_nbr(ap, params);
    char output[my_longlonglen(value, 8)];
    int len = 0;

    if (my_char_in(params.amplifiers, '#'))
        len += my_fd_putstr(params.fd, "0");
    if (params.precision != -1)
        return (-2);
    my_lltoa(output, value, 8);
    len += my_fd_putstr(params.fd, output);
    return (len);
}