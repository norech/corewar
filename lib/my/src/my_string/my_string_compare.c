/*
** EPITECH PROJECT, 2021
** string_equals
** File description:
** Source code
*/

#include <my/string.h>
#include <my/str.h>

int my_string_compare(string_t const *s1, string_t const *s2)
{
    return (my_strcmp(s1->as_str, s2->as_str));
}