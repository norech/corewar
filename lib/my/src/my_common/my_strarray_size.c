/*
** EPITECH PROJECT, 2021
** my_strarray_size
** File description:
** Source code
*/
#include <stdlib.h>

int my_strarray_size(char **args)
{
    int len = 0;

    for (int i = 0; args[i] != NULL; i++)
        len++;
    return (len);
}