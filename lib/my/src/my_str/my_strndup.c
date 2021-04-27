/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Duplicates str
*/
#include <stdlib.h>
#include <my.h>

mut_str_t my_strndup(str_t src, int n)
{
    char *dup = malloc(sizeof(char) * (n + 1));

    if (dup == NULL)
        return (NULL);
    my_strncpy(dup, src, n);
    dup[n] = '\0';
    return (dup);
}
