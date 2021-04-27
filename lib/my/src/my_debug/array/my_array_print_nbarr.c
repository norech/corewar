/*
** EPITECH PROJECT, 2020
** my_array_print_nbarr
** File description:
** Source code
*/
#include <my/def.h>
#include <my/io.h>
#include <my/array.h>
#include <my/common.h>
#include <stdlib.h>


void my_array_print_nbarr(size_t element_size, char* format, void *arr,
    ssize_t size)
{
    unsigned char *bytes = (unsigned char *)arr;
    unsigned long long nbr = 0;

    if (size < 0)
        size = my_array_count(element_size, bytes);
    for (int i = 0; i < size; i++) {
        if (i != 0)
            my_dprintf(2, ", ");
        my_memcpy(&nbr, bytes, element_size);
        my_dprintf(2, format, nbr);
        bytes += element_size;
    }
}