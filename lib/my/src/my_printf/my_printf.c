/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** Source code
*/

#include <unistd.h>
#include <my.h>
#include <stdarg.h>
#include <stdbool.h>
#include <my/utils/printf_utils.h>
#include <stdio.h>

int my_printf(char *s, ...)
{
    int chars = 0;
    va_list ap;

    va_start(ap, s);
    while (*s) {
        if (*s == '%') {
            s++;
            chars += parse_flag(1, &ap, &s, chars);
            continue;
        }
        chars += write(1, s, 1);
        s++;
    }
    va_end(ap);

    return (chars);
}