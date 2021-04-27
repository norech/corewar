/*
** EPITECH PROJECT, 2020
** my_printf_parser
** File description:
** Source code
*/
#include <my/utils/printf_utils.h>
#include <my.h>
#include <stdbool.h>

bool is_token_present(char **s, char token)
{
    if (**s == token) {
        (*s)++;
        return (true);
    }
    return (false);
}

char *parse_tokens_taken_in_list(char *output, char **s, char *list)
{
    int i = 0;
    int j = 0;
    char *old_s = *s - 1;

    my_bzero(output, 16);
    while (*s != old_s) {
        old_s = *s;
        while (list[i] && i < 16) {
            if (is_token_present(s, list[i]) && !my_char_in(output, list[i])) {
                output[j] = list[i];
                j++;
            }
            i++;
        }
    }
    output[j] = '\0';
    return (output);
}

long long parse_number(char **s)
{
    long long nb = -1;

    if (**s >= '0' && **s <= '9')
        nb = 0;
    while (**s >= '0' && **s <= '9') {
        nb = nb * 10 + (**s - '0');
        (*s)++;
    }
    return (nb);
}