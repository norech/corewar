/*
** EPITECH PROJECT, 2020
** my_printf_utils
** File description:
** Source code
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <my/types.h>

#ifndef MY_PRINTF_UTILS_H
#define MY_PRINTF_UTILS_H

typedef struct printf_flag_parameters {
    char amplifiers[16];
    int width;
    int precision;
    fd_t fd;
    str_t length_flag;
} printf_flag_parameters_t;

bool is_token_present(char **s, char token);
char* parse_tokens_taken_in_list(char *output, char **s, char *list);
long long parse_number(char **s);
int parse_flag(fd_t fd, va_list *ap, char **s, int bytes_written);

long long converted_va_arg_nbr(va_list *ap, printf_flag_parameters_t params);
unsigned long long converted_va_arg_unsigned_nbr(va_list *ap,
    printf_flag_parameters_t params);

int my_printf_put_percent(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_float(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_exp_lower(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_exp_upper(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_unsigned_nbr(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_nbr(va_list *ap, printf_flag_parameters_t params);
int my_printf_putstr(va_list *ap, printf_flag_parameters_t params);
int my_printf_putstr_printable(va_list *ap, printf_flag_parameters_t params);
int my_printf_putchar(va_list *ap, printf_flag_parameters_t params);
int my_printf_putptr(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_binary(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_octal(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_hexa_lower(va_list *ap, printf_flag_parameters_t params);
int my_printf_put_hexa_upper(va_list *ap, printf_flag_parameters_t params);

typedef struct print_flag_element {
    char flag;
    int (*method)(va_list *ap, printf_flag_parameters_t params);
    char *amplifiers;
    str_t *length_flags;
} print_flag_element_t;

typedef struct print_scanned_flag {
    print_flag_element_t flag;
    str_t length_flag;
} print_scanned_flag_t;

#define ABS(x) (x < 0 ? -x : x)

#endif //MY_PRINTF_UTILS_H