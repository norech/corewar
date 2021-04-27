/*
** EPITECH PROJECT, 2020
** my_array_count
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void *my_array_find_one(size_t element_size, void *array,
    bool (*cmp)(size_t element_size, void *element, void *param), void *param)
{
    int len = my_array_count(element_size, array);
    unsigned char *bytes = (unsigned char *)array;

    for (int i = 0; i < len; i++) {
        if (cmp(element_size, bytes, param))
            return (bytes);
        bytes += element_size;
    }
    return (NULL);
}
