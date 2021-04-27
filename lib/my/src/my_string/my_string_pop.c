/*
** EPITECH PROJECT, 2021
** string_pop_back
** File description:
** Source code
*/

#include <my/string.h>
#include <my/str.h>
#include <my/types.h>

char my_string_pop(string_t *self)
{
    char c;

    if (self->length == 0)
        return ('\0');
    self->length--;
    c = self->as_str[self->length];
    self->as_str[self->length] = '\0';
    return (c);
}