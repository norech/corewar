/*
** EPITECH PROJECT, 2021
** my_string_reserve
** File description:
** Source code
*/
#include <my/string.h>
#include <my/types.h>
#include <my/math.h>

void my_string_reserve(string_t *self, usize_t size)
{
    mut_str_t tmp;
    usize_t expand_size = 0;
    usize_t cumulated_size = self->length + size;

    if (cumulated_size >= self->capacity) {
        expand_size = cumulated_size - self->capacity;
        self->capacity += sizeof(char) * MAX(128, expand_size + 1);
        tmp = self->as_str;
        self->as_str = malloc(self->capacity);
        if (self->as_str == NULL) {
            free(tmp);
            return;
        }
        my_strcpy(self->as_str, tmp);
        free(tmp);
    }
}