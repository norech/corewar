/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** Parses a number
*/
#include <my.h>

static int may_overflow_if_pushed(int number, int digit)
{
    return (number > 2147483647 - (number * 9 + digit));
}

static int process_digit(bool *has_started_number, int *number, char c)
{
    if (c >= '0' && c <= '9') {
        if (may_overflow_if_pushed(*number, c - '0')) {
            *number = 0;
            return (true);
        }
        *number = *number * 10 + (c - '0');
        *has_started_number = true;
    } else if (c != ' ' && c != '+' && c != '-') {
        return (true);
    }
    return (false);
}

RES(int) my_getnbr(char const *str)
{
    int number = 0;
    int multiplier = 1;
    bool has_started_number = false;
    int i = 0;

    while (str[i] != '\0') {
        char c = str[i];
        if (c == '-' && !has_started_number) {
            multiplier *= -1;
        }
        if (multiplier == -1 && number == 214748364 && c == '8') {
            return (OK(int, -2147483648));
        }
        if (process_digit(&has_started_number, &number, c))
            break;
        i++;
    }
    if (!has_started_number)
        return (ERR(int));
    return (OK(int, multiplier * number));
}
