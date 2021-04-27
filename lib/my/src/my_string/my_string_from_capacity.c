/*
** EPITECH PROJECT, 2021
** new_string
** File description:
** Source code
*/

#include <my/str.h>
#include <my/string.h>
#include <my/types.h>

string_t *my_string_from_capacity(usize_t capacity)
{
    string_t *s = malloc(sizeof(string_t));
    mut_str_t str = malloc(sizeof(char) * capacity);

    if (s == NULL || str == NULL)
        return (NULL);
    str[0] = '\0';
    s->is_allocated = true;
    s->as_str = str;
    s->length = 0;
    s->capacity = capacity;
    return (s);
}