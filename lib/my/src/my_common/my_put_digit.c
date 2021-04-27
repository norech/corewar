/*
** EPITECH PROJECT, 2020
** my_put_digit
** File description:
** Print a digit in any base
*/
#include <my.h>

int my_put_digit(int i)
{
    return (my_putchar(my_get_digit_char(i)));
}
