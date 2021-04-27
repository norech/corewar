/*
** EPITECH PROJECT, 2020
** my_listmerge
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void *my_array_slice(size_t element_size, void *array, size_t start, size_t end)
{
    size_t arr_size = end - start;
    void *output = malloc(element_size * (arr_size + 1));

    if (output == NULL)
        return (NULL);
    my_memcpy(output, array + (start * element_size),
        element_size * arr_size);
    my_memset(output + (arr_size * element_size), 0, element_size);
    return (output);
}