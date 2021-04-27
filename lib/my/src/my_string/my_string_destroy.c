/*
** EPITECH PROJECT, 2021
** string_destroy
** File description:
** Source code
*/

#include <my/string.h>
#include <stdlib.h>

void my_string_destroy(string_t *s)
{
    free(s->as_str);
    s->as_str = NULL;
    s->length = 0;
    s->capacity = 0;
    if (s->is_allocated) {
        free(s);
    }
}