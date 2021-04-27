/*
** EPITECH PROJECT, 2020
** my_printf_convert
** File description:
** Source code
*/
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <my/utils/printf_utils.h>
#include <my.h>

long long converted_va_arg_nbr(va_list *ap, printf_flag_parameters_t params)
{
    if (my_strcmp(params.length_flag, "ll") == 0)
        return va_arg(*ap, long long);
    if (my_strcmp(params.length_flag, "l") == 0)
        return va_arg(*ap, long);
    if (my_strcmp(params.length_flag, "hh") == 0)
        return (char)va_arg(*ap, int);
    if (my_strcmp(params.length_flag, "h") == 0)
        return (short)va_arg(*ap, int);
    return va_arg(*ap, int);
}

unsigned long long converted_va_arg_unsigned_nbr(va_list *ap,
    printf_flag_parameters_t params)
{
    if (my_strcmp(params.length_flag, "ll") == 0)
        return va_arg(*ap, unsigned long long);
    if (my_strcmp(params.length_flag, "l") == 0)
        return va_arg(*ap, unsigned long);
    if (my_strcmp(params.length_flag, "hh") == 0)
        return (unsigned char)va_arg(*ap, unsigned int);
    if (my_strcmp(params.length_flag, "h") == 0)
        return (unsigned short)va_arg(*ap, unsigned int);
    return va_arg(*ap, unsigned int);
}