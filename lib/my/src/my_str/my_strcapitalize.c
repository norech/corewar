/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** Put capital case to string
*/
#include <my.h>

static int is_capitalize_separator_char(char c)
{
    return (c == ' ' || c == '-' || c == '+' || c == ';');
}

static char change_case(char c, int uppercase)
{
    if (c >= 'a' && c <= 'z' && uppercase) {
        return (c - 32);
    } else if (c >= 'A' && c <= 'Z' && !uppercase) {
        return (c + 32);
    }
    return c;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (i == 0 || is_capitalize_separator_char(str[i - 1])) {
            str[i] = change_case(str[i], 1);
        } else {
            str[i] = change_case(str[i], 0);
        }
        i++;
    }

    return (str);
}
