/*
** EPITECH PROJECT, 2020
** my_listmerge
** File description:
** Source code
*/
#include <my.h>
#include <my/array.h>

void *my_array_merge(size_t element_size, void **elements)
{
    int len = 0;
    int arr_len = 0;
    int offset = 0;
    int pos = 0;
    unsigned char *output;

    FOREACH (elements, i)
        len += my_array_count(element_size, elements[i]);
    output = malloc(element_size * (len + 1));
    if (output == NULL)
        return (NULL);
    FOREACH (elements, i) {
        arr_len = my_array_count(element_size, elements[i]);
        for (int j = 0; j < arr_len; j++) {
            offset = j * element_size;
            my_memcpy(output + pos, elements[i] + offset, element_size);
            pos += element_size;
        }
    }
    my_memset(output + pos, 0, element_size);
    return (output);
}