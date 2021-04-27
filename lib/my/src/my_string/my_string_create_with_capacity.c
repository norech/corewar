/*
** EPITECH PROJECT, 2021
** new_string
** File description:
** Source code
*/

#include <my/str.h>
#include <my/string.h>

string_t *my_string_create_with_capacity(string_t *s, usize_t capacity)
{
    mut_str_t str = malloc(sizeof(char) * capacity);

    if (str == NULL)
        return (NULL);
    str[0] = '\0';
    s->is_allocated = false;
    s->as_str = str;
    s->length = 0;
    s->capacity = capacity;
    return (s);
}