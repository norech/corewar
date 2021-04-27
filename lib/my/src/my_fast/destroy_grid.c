/*
** EPITECH PROJECT, 2021
** destroy_grid
** File description:
** Source code
*/

#include <my/types.h>
#include <stdlib.h>
#include <my/fast.h>

void destroy_char_grid(char_grid_t *grid)
{
    int i;

    for (i = 0; i < grid->size_y; i++) {
        free(grid->elements[i]);
    }
    free(grid->elements);
    free(grid);
}

void destroy_int_grid(int_grid_t *grid)
{
    int i;

    for (i = 0; i < grid->size_y; i++) {
        free(grid->elements[i]);
    }
    free(grid->elements);
    free(grid);
}