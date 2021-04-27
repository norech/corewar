/*
** EPITECH PROJECT, 2021
** new_string
** File description:
** Source code
*/

#include <my/str.h>
#include <my/string.h>
#include <my/types.h>

string_t *my_string_assign(string_t *s, str_t str)
{
    usize_t len = my_strlen(str);

    s->length = len;
    if (s->capacity <= len) {
        free(s->as_str);
        s->as_str = malloc(sizeof(char) * (len + 1));
        s->capacity = len + 1;
    }
    if (s->as_str == NULL)
        return (NULL);
    my_strcpy(s->as_str, str);
    return (s);
}