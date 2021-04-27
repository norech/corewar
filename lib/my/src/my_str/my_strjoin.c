/*
** EPITECH PROJECT, 2020
** my_strjoin
** File description:
** Source code
*/
#include <my/str.h>
#include <my.h>

static int get_joined_length(str_t *arr, str_t delimiter)
{
    int len = 0;
    int delimiter_len = my_strlen(delimiter);

    FOREACH (arr, i) {
        if (i != 0)
            len += delimiter_len;
        len += my_strlen(arr[i]);
    }
    return (len);
}

mut_str_t my_strjoin(str_t *arr, str_t delimiter)
{
    str_t tmp;
    int len = get_joined_length(arr, delimiter);
    char *output = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (output == NULL)
        return (NULL);
    FOREACH (arr, j) {
        tmp = arr[j];
        if (i != 0)
            FOREACH(delimiter, j)
                output[i++] = delimiter[j];
        ITERATE(tmp) {
            output[i++] = *tmp;
        }
    }
    output[i] = '\0';
    return (output);
}