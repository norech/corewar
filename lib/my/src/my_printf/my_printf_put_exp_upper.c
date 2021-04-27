/*
** EPITECH PROJECT, 2020
** my_void_put_float
** File description:
** Source code
*/
#include <my.h>
#include <my/io.h>
#include <my/utils/printf_utils.h>
#include <stdarg.h>

int my_printf_put_exp_upper(va_list *ap, printf_flag_parameters_t params)
{
    int len = 0;
    int exponent = 0;
    float value = va_arg(*ap, double);

    if (my_char_in(params.amplifiers, '+') && value >= 0)
        len += my_fd_putchar(params.fd, '+');
    value = my_float_to_exponent(value, &exponent);
    value = my_round_float(value, 6);
    len += my_fd_put_float(params.fd, value, 6);
    len += my_fd_putchar(params.fd, 'E');
    if (exponent >= 0)
        len += my_fd_putchar(params.fd, '+');
    if (exponent < 10)
        len += my_fd_putchar(params.fd, '0');
    len += my_fd_put_nbr(params.fd, exponent);
    return (len);
}