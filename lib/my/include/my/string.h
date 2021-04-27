/*
** EPITECH PROJECT, 2021
** my_string
** File description:
** Source code
*/

#ifndef MY_STRING_H
#define MY_STRING_H
#include <stdlib.h>
#include <my/str.h>
#include <my/types.h>

typedef struct string string_t;

struct string {
    bool is_allocated;
    mut_str_t as_str;
    usize_t length;
    usize_t capacity;
};

string_t *my_string_from(str_t str);
string_t *my_string_from_capacity(usize_t capacity);
string_t *my_string_create(string_t *s, str_t str);
string_t *my_string_create_raw(string_t *s, mut_str_t str);
string_t *my_string_create_with_capacity(string_t *s, usize_t capacity);
void my_string_destroy(string_t *s);
string_t *my_string_append(string_t *s, string_t const *str);
isize_t my_string_indexof(string_t const *s, string_t const *str);
int my_string_compare(string_t const *s1, string_t const *s2);
string_t *my_string_assign(string_t *s, str_t str);
usize_t my_string_push(string_t *s, char c);
usize_t my_string_push_str(string_t *s, str_t str);
char my_string_pop(string_t *s);
void my_string_reserve(string_t *self, usize_t size);

#endif //MY_STRING_H