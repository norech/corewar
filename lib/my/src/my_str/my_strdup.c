/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Duplicates str
*/
#include <stdlib.h>
#include <my.h>

char *my_strdup(str_t src)
{
    char *dup = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dup == NULL)
        return (NULL);
    my_strcpy(dup, src);
    return (dup);
}
