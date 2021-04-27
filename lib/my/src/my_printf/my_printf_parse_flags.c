/*
** EPITECH PROJECT, 2020
** my_printf_parse
** File description:
** Source code
*/
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <my/utils/printf_utils.h>
#include <my.h>
#include <my/io.h>

static str_t default_len_mod[] = {""};
static str_t numeric_len_mod[] = {"l", "ll", "h", "hh", ""};

static const print_flag_element_t print_flags[] = {
    {'s', &my_printf_putstr, "-", default_len_mod},
    {'S', &my_printf_putstr_printable, "-", default_len_mod},
    {'c', &my_printf_putchar, "-", default_len_mod},
    {'%', &my_printf_put_percent, "-", default_len_mod},
    {'u', &my_printf_put_unsigned_nbr, "-+0 ", numeric_len_mod},
    {'d', &my_printf_put_nbr, "-+0 ", numeric_len_mod},
    {'i', &my_printf_put_nbr, "-+0 ", numeric_len_mod},
    {'p', &my_printf_putptr, "-+", default_len_mod},
    {'f', &my_printf_put_float, "-+", default_len_mod},
    {'e', &my_printf_put_exp_lower, "-+", default_len_mod},
    {'E', &my_printf_put_exp_upper, "-+", default_len_mod},
    {'b', &my_printf_put_binary, "-+#", numeric_len_mod},
    {'o', &my_printf_put_octal, "-+#", numeric_len_mod},
    {'x', &my_printf_put_hexa_lower, "-+#", numeric_len_mod},
    {'X', &my_printf_put_hexa_upper, "-+#", numeric_len_mod},
    {'n', NULL, "-", default_len_mod},
    {'\0', NULL, NULL, NULL }
};

static bool handle_n_flag(print_flag_element_t flag, va_list *ap,
    int bytes_written)
{
    if (flag.flag != 'n')
        return (false);

    int *ptr = va_arg(*ap, int *);
    *ptr = bytes_written;
    return (true);
}

static str_t parse_flag_type(char **s, print_flag_element_t flag)
{
    str_t output = NULL;
    int flaglen;
    int i = 0;
    str_t *length_flags = flag.length_flags;

    while (length_flags[i]) {
        flaglen = my_strlen(length_flags[i]);
        if (my_strncmp(*s, length_flags[i], flaglen) == 0) {
            *s += flaglen;
            output = length_flags[i];
            break;
        }
        i++;
    }
    if (output == NULL)
        output = "";
    return (output);
}

static print_scanned_flag_t scan_flag_element(char **s)
{
    print_flag_element_t flag;
    print_scanned_flag_t scanned;
    int i = 0;

    while (print_flags[i].flag != '\0') {
        flag = print_flags[i];
        scanned.length_flag = parse_flag_type(s, flag);
        if (**s == flag.flag) {
            (*s)++;
            break;
        }
        i++;
    }
    if (print_flags[i].flag == '\0')
        scanned.flag = print_flags[i];
    else
        scanned.flag = flag;
    return (scanned);
}

static int parse_format_string(fd_t fd, va_list *ap, char **s,
    int bytes_written)
{
    int i = 0;
    print_scanned_flag_t scanned;
    printf_flag_parameters_t params;

    parse_tokens_taken_in_list(params.amplifiers, s, "-+# 0");
    params.fd = fd;
    params.width = parse_number(s);
    params.precision = (is_token_present(s, '.') ? parse_number(s) : -1);
    scanned = scan_flag_element(s);
    params.length_flag = scanned.length_flag;
    if (scanned.flag.flag == '\0')
        return (-2);
    while (params.amplifiers[i]) {
        if (!my_char_in(scanned.flag.amplifiers, params.amplifiers[i]))
            return (-2);
        i++;
    }
    if (handle_n_flag(scanned.flag, ap, bytes_written))
        return (0);
    return (scanned.flag.method(ap, params));
}

int parse_flag(fd_t fd, va_list *ap, char **s, int bytes_written)
{
    char *start = *s;
    int return_value = -2;

    if (**s == '\0')
        return (0);
    return_value = parse_format_string(fd, ap, s, bytes_written);
    if (return_value != -2)
        return (return_value);
    start--;
    return_value = 0;
    while (start < *s) {
        return_value += my_fd_putchar(fd, *start);
        start++;
    }
    return (return_value);
}
