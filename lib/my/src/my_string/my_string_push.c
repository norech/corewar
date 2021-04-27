/*
** EPITECH PROJECT, 2021
** string_push_back
** File description:
** Source code
*/

#include <my/string.h>
#include <my/str.h>
#include <my/types.h>

usize_t my_string_push(string_t *self, char c)
{
    return (my_string_push_str(self, (char[2]) { c, 0 }));
}