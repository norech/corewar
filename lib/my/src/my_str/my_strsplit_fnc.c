/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** Source
*/
#include <stdlib.h>
#include <my/all.h>
#include <my/str.h>
#include <my/types.h>

static void fill_words_lengths(str_t str, int *lengths_ptr,
    bool (*delim)(strpos_t pos))
{
    int i = 0;
    int j = 0;
    bool is_separator = false;
    bool was_separator = true;

    lengths_ptr[0] = 0;
    while (*str != '\0') {
        is_separator = delim(str);
        if (was_separator && !is_separator) {
            j += (i != 0);
            i = 0;
            lengths_ptr[j] = 0;
        } else {
            lengths_ptr[j]++;
            i++;
        }
        str++;
        was_separator = is_separator;
    }
    lengths_ptr[j]++;
}

static void fill_words(mut_str_t *words, str_t str,
    int const *lengths, bool (*delim)(strpos_t pos))
{
    int i = 0;
    int j = 0;
    int word_pos = 0;
    bool was_separator = false;

    words[j] = malloc(sizeof(char) * (lengths[j] + 1));
    while (str[i] != '\0') {
        bool is_separator = delim(&str[i]);
        words[j][word_pos] = (was_separator && !is_separator) ? '\0' : str[i];
        if (was_separator && !is_separator) {
            j += (i != 0);
            words[j] = malloc(sizeof(char) * (lengths[j] + 1));
            word_pos = 0;
        } else {
            word_pos += !is_separator;
            i++;
        }
        was_separator = is_separator;
    }
    words[j][word_pos] = '\0';
}

static int count_words(str_t str, bool (*delim)(strpos_t pos))
{
    int i = 0;
    bool is_separator = false;
    bool was_separator = true;

    while (*str != '\0') {
        is_separator = delim(str);
        if (was_separator && !is_separator)
            i++;
        str++;
        was_separator = is_separator;
    }
    return (i);
}

mut_str_t *my_strsplit_fnc(str_t str, bool (*delim)(strpos_t pos))
{
    int words_count = count_words(str, delim);
    int *lengths = malloc(sizeof(int) * words_count);
    mut_str_t *words = malloc(sizeof(str_t) * (words_count + 1));

    if (lengths == NULL || words == NULL)
        return (NULL);
    fill_words_lengths(str, lengths, delim);
    fill_words(words, str, lengths, delim);
    words[words_count] = NULL;
    free(lengths);
    return (words);
}
