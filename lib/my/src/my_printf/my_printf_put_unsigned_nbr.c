/*
** EPITECH PROJECT, 2020
** my_void_put_nbr
** File description:
** Source code
*/
#include <my.h>
#include <my/io.h>
#include <my/utils/printf_utils.h>
#include <stdarg.h>

static int get_max_padding(int numlen, printf_flag_parameters_t *params)
{
    int max;

    if (params->precision == -1) {
        max = params->width - numlen;
    } else {
        max = params->precision - numlen;
    }
    if (my_char_in(params->amplifiers, '+')
        || my_char_in(params->amplifiers, ' '))
        max--;
    else if (params->precision != -1)
        max--;
    return (max);
}

static int put_padding(unsigned long long value,
    printf_flag_parameters_t *params)
{
    int i = 0;
    int len = 0;
    int numlen = my_longlonglen(value, 10);
    int max = get_max_padding(numlen, params);

    if (!my_char_in(params->amplifiers, '0')) {
        for (; i < max; i++) {
            len += my_fd_putchar(params->fd, ' ');
        }
    }
    return (len);
}

static int put_zeroes(unsigned long long value,
    printf_flag_parameters_t *params)
{
    int i = 0;
    int len = 0;
    int numlen = my_longlonglen(value, 10);
    int max = get_max_padding(numlen, params);
    if (params->precision != -1)
        max++;
    if (my_char_in(params->amplifiers, '0')
        || params->precision != -1) {
        for (; i < max; i++) {
            len += my_fd_putchar(params->fd, '0');
        }
    }
    return (len);
}

static int put_sign(printf_flag_parameters_t *params)
{
    int len = 0;

    if (my_char_in(params->amplifiers, '+'))
        len += my_fd_putchar(params->fd, '+');
    if (my_char_in(params->amplifiers, ' '))
        len += my_fd_putchar(params->fd, ' ');
    return (len);
}

int my_printf_put_unsigned_nbr(va_list *ap, printf_flag_parameters_t params)
{
    int len = 0;
    unsigned long long value = converted_va_arg_unsigned_nbr(ap, params);
    bool show_zeroes = (my_char_in(params.amplifiers, '0')
                        || params.precision != -1);

    if (params.precision != -1 && my_char_in(params.amplifiers, '0'))
        return (-2);
    if (my_char_in(params.amplifiers, '+')
        && my_char_in(params.amplifiers, ' '))
        return (-2);
    if (!show_zeroes && !my_char_in(params.amplifiers, '-'))
        len += put_padding(value, &params);
    len += put_sign(&params);
    if (show_zeroes)
        len += put_zeroes(value, &params);
    len += my_fd_put_u_nbr(params.fd, value);
    if (!show_zeroes && my_char_in(params.amplifiers, '-'))
        len += put_padding(value, &params);
    return (len);
}