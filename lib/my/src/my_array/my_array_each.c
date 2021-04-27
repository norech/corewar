/*
** EPITECH PROJECT, 2020
** my_array_each
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void my_array_each(size_t element_size, void *array,
    void (*iter)(void *val))
{
    int len = my_array_count(element_size, array);
    unsigned char *bytes = (unsigned char *)array;

    for (int i = 0; i < len; i++) {
        iter(bytes);
        bytes += element_size;
    }
}