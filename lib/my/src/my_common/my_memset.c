/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** Set bytes to zero
*/
#include <stdlib.h>

void *my_memset(void *res, char fill, size_t size)
{
    unsigned char *bytes = (unsigned char *)res;

    size--;
    while (size) {
        bytes[size] = fill;
        size--;
    }
    bytes[size] = fill;
    return (res);
}