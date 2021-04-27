/*
** EPITECH PROJECT, 2021
** new_string
** File description:
** Source code
*/

#include <my/str.h>
#include <my/string.h>
#include <my/types.h>

string_t *my_string_from(str_t str)
{
    string_t *s = malloc(sizeof(string_t));

    if (s == NULL)
        return (NULL);
    s->is_allocated = true;
    s->as_str = my_strdup(str);
    s->length = my_strlen(str);
    s->capacity = s->length + 1;
    return (s);
}