/*
** EPITECH PROJECT, 2021
** new_string
** File description:
** Source code
*/

#include <my/str.h>
#include <my/string.h>

string_t *my_string_create_raw(string_t *s, mut_str_t str)
{
    s->is_allocated = false;
    s->as_str = str;
    s->length = my_strlen(str);
    s->capacity = s->length + 1;
    return (s);
}