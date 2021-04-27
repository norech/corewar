/*
** EPITECH PROJECT, 2020
** my_array_count
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void **my_array_find_all(size_t element_size, void *array,
    bool (*cmp)(size_t element_size, void *element, void *param), void *param)
{
    int len = my_array_count(element_size, array);
    unsigned char *bytes = (unsigned char *)array;
    unsigned char *elements[len * element_size];
    int j = 0;

    my_memset(elements, 0, len * element_size);
    for (int i = 0; i < len; i++) {
        if (cmp(element_size, bytes, param)) {
            elements[j] = bytes;
            j++;
        }
        bytes += element_size;
    }
    elements[j] = NULL;
    return (my_arraydup(sizeof(void *), elements));
}