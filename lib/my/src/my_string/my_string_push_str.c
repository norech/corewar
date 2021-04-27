/*
** EPITECH PROJECT, 2021
** string_append
** File description:
** Source code
*/

#include <my/string.h>
#include <my/str.h>
#include <my/types.h>

usize_t my_string_push_str(string_t *self, str_t str)
{
    usize_t size = self->length;
    string_t s;

    my_string_create_raw(&s, (mut_str_t)str);
    my_string_append(self, &s);
    return (self->length - size);
}