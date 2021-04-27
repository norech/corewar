/*
** EPITECH PROJECT, 2020
** my_get_digit_char
** File description:
** Get char representing graphically the digit
*/
#include <my.h>

char my_get_digit_char(int i)
{
    if (i > 15)
        return ('\0');
    if (i > 9)
        return (55 + i);
    else
        return (48 + i);
    return (0);
}
