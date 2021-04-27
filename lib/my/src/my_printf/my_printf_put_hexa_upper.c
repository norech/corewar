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

int my_printf_put_hexa_upper(va_list *ap, printf_flag_parameters_t params)
{
    int len = 0;
    unsigned long long value = converted_va_arg_unsigned_nbr(ap, params);
    char output[my_longlonglen(value, 16)];

    if (my_char_in(params.amplifiers, '#'))
        len += my_fd_putstr(params.fd, "0X");
    if (params.precision != -1)
        return (-2);
    my_lltoa(output, value, 16);
    my_strupcase(output);
    len += my_fd_putstr(params.fd, output);
    return (len);
}