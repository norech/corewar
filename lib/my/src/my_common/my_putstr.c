/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Puts a string
*/
#include <my.h>

int my_putstr(char const *str)
{
    char *chr = (char *) str;
    int len = 0;

    while (*chr != '\0') {
        if (my_putchar(*chr) < 0)
            break;
        chr++;
        len++;
    }
    return (len);
}
