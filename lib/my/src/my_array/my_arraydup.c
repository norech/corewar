/*
** EPITECH PROJECT, 2020
** my_listmerge
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void *my_arraydup(size_t element_size, void *array)
{
    int len = my_array_count(element_size, array);
    void *output = malloc(element_size * (len + 1));

    if (output == NULL)
        return (NULL);
    my_memcpy(output, array, element_size * (len + 1));
    return (output);
}