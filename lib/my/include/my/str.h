/*
** EPITECH PROJECT, 2020
** my_str
** File description:
** Source code
*/
#include <unistd.h>
#include <stdbool.h>
#include <my/types.h>

#ifndef MY_STR_H
#define MY_STR_H

strpos_t   my_strstr(str_t str, str_t to_find);

int        my_strcmp(str_t s1, str_t s2);

int        my_strncmp(str_t s1, str_t s2, int n);

bool       my_str_isalpha(str_t str);

bool       my_str_isnum(str_t str);

bool       my_str_islower(str_t str);

bool       my_str_isupper(str_t str);

bool       my_str_isprintable(str_t str);

bool       my_char_in(str_t haystack, char needle);

bool       my_str_startswith(str_t haystack, str_t needle);

bool       my_str_endswith(str_t haystack, str_t needle);

int        my_strlen(str_t str);

int        my_strcount(str_t haystack, str_t needle);

mut_str_t  my_strpad_start(mut_str_t dest, char pattern, int size);

mut_str_t  my_strpad_end(mut_str_t dest, char pattern, int size);

mut_str_t  my_bzero(mut_str_t res, size_t size);

mut_str_t  my_strcpy(mut_str_t dest, str_t src);

mut_str_t  my_strncpy(mut_str_t dest, str_t src, int n);

mut_str_t  my_strdup(str_t src);

mut_str_t  my_strndup(str_t src, int n);

mut_str_t  my_strtake(mut_str_t str, int index, int count);

mut_str_t  my_revstr(mut_str_t str);

mut_str_t  my_strupcase(mut_str_t str);

mut_str_t  my_strlowcase(mut_str_t str);

mut_str_t  my_strcapitalize(mut_str_t str);

mut_str_t  my_strcat(mut_str_t dest, str_t src);

mut_str_t  my_strncat(mut_str_t dest, str_t src, int nb);

mut_str_t  my_strinvertcase(mut_str_t str);

mut_str_t  my_strjoin(str_t *arr, str_t delimiter);

mut_str_t  my_substr(str_t str, int start, int end);

mut_str_t  my_str_repeat(str_t str, int count);

mut_str_t  my_strconcat(int argc, ...);

mut_str_t *my_strsplit(str_t str, str_t delimiter);

mut_str_t *my_strsplit_fnc(str_t str, bool (*delim)(strpos_t pos));


static inline bool is_char_printable(char c)
{
    return (c >= 31 && c < 127);
}

static inline bool is_char_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

static inline bool is_char_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

static inline bool is_char_alpha(char c)
{
    return (is_char_lowercase(c) || is_char_uppercase(c));
}

static inline bool is_char_num(char c)
{
    return (c >= '0' && c <= '9');
}

#define CONCAT(...) \
    my_strjoin((str_t[]){ "", ## __VA_ARGS__, NULL }, "")

#define JOIN(joint, ...) \
    my_strjoin((str_t[]){ "", ## __VA_ARGS__, NULL }, joint)

#endif //MY_STR_H
