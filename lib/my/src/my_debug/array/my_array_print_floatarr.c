/*
** EPITECH PROJECT, 2020
** my_array_print_nbarr
** File description:
** Source code
*/
#include <my/def.h>
#include <my/io.h>
#include <my.h>

void my_array_print_floatarr(float *arr, ssize_t size)
{
    if (size < 0) {
        FOREACH(arr, i) {
            if (i != 0)
                my_dprintf(2, ", ");
            my_dprintf(2, "%.2f", arr[i]);
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (i != 0)
                my_dprintf(2, ", ");
            my_dprintf(2, "%.2f", arr[i]);
        }
    }
}