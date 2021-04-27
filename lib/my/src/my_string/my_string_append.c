/*
** EPITECH PROJECT, 2021
** string_append
** File description:
** Source code
*/

#include <my/string.h>
#include <my/str.h>
#include <my/types.h>

string_t *my_string_append(string_t *self, string_t const *s)
{
    my_string_reserve(self, s->length + 1);
    if (self->as_str == NULL)
        return (NULL);
    my_strcat(self->as_str + self->length, s->as_str);
    self->length += s->length;
    return (self);
}