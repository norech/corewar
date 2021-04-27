/*
** EPITECH PROJECT, 2020
** my_bzero
** File description:
** Set bytes to zero in a char
*/
#include <my.h>

char *my_bzero(char *res, size_t size)
{
    return (my_memset(res, '\0', size));
}