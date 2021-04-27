/*
** EPITECH PROJECT, 2020
** my_strsplit
** File description:
** Splits str to word array
*/

#include <my.h>
#include <stdlib.h>

static void fill_words_lengths(str_t str,
    int *lengths_ptr, str_t separator)
{
    int i = 0;
    int j = 0;
    int sep_len = my_strlen(separator);

    lengths_ptr[j] = 0;
    while (*str != '\0') {
        if (my_strncmp(str, separator, sep_len) == 0) {
            j++;
            i = 0;
            lengths_ptr[j] = 0;
            str += sep_len;
        } else {
            lengths_ptr[j]++;
            i++;
            str++;
        }
    }
}

static void fill_words(mut_str_t *words, str_t str,
    int const *lengths, str_t separator)
{
    int i = 0;
    int j = 0;
    int word_pos = 0;
    int sep_len = my_strlen(separator);

    words[j] = malloc(sizeof(char) * (lengths[j] + 1));
    while (str[i] != '\0') {
        if (my_strncmp(str + i, separator, sep_len) == 0) {
            words[j][word_pos] = '\0';
            j++;
            words[j] = malloc(sizeof(char) * (lengths[j] + 1));
            word_pos = 0;
            i += sep_len;
        } else {
            words[j][word_pos] = str[i];
            word_pos++;
            i++;
        }
    }
    words[j][word_pos] = '\0';
}

static int count_words(str_t str, str_t separator)
{
    int i = 1;
    int sep_len = my_strlen(separator);

    while (*str) {
        if (my_strncmp(str, separator, sep_len) == 0) {
            i++;
            str += sep_len;
        } else {
            str++;
        }
    }
    return (i);
}

mut_str_t *my_strsplit(str_t str, str_t separator)
{
    int words_count = count_words(str, separator);
    int *lengths = malloc(sizeof(int) * (words_count));
    char **words;

    if (lengths == NULL)
        return (NULL);
    fill_words_lengths(str, lengths, separator);
    words = malloc(sizeof(char *) * (words_count + 1));
    if (words == NULL)
        return (NULL);
    fill_words(words, str, lengths, separator);
    words[words_count] = NULL;
    free(lengths);
    return (words);
}
