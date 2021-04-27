/*
** EPITECH PROJECT, 2020
** with_value
** File description:
** Source code
*/
#include <my.h>

bool with_value(size_t element_size, void *element, void *ref)
{
    unsigned char *element_bytes = (unsigned char *)element;
    unsigned char *ref_bytes = (unsigned char *)&ref;

    for (size_t i = 0; i < element_size; i++) {
        if (element_bytes[i] != ref_bytes[i])
            return (false);
    }
    return (true);
}