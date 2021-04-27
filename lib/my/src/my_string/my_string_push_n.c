/*
** EPITECH PROJECT, 2021
** string_push_back
** File description:
** Source code
*/

#include <my/string.h>
#include <my/str.h>
#include <my/types.h>

usize_t my_string_push_n(string_t *self, char *chars, size_t n)
{
    char tmp[n + 1];

    my_strncpy(tmp, chars, n);
    tmp[n] = '\0';
    return (my_string_push_str(self, tmp));
}