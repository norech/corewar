/*
** EPITECH PROJECT, 2020
** my_array_each
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void *my_array_map(size_t element_size, void *array,
    void *(*iter)(int i, void *val))
{
    int len = my_array_count(element_size, array);
    unsigned char *bytes = (unsigned char *)array;
    void *tmp;

    for (int i = 0; i < len; i++) {
        tmp = iter(i, bytes);
        my_memcpy(bytes, tmp, element_size);
        free(tmp);
        bytes += element_size;
    }
    return (array);
}