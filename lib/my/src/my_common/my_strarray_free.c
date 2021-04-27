/*
** EPITECH PROJECT, 2021
** my_strarray_free
** File description:
** Source code
*/
#include <stdlib.h>

void my_strarray_free(char **array)
{
    int i = 0;

    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}