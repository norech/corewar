/*
** EPITECH PROJECT, 2021
** fill_grid
** File description:
** Source code
*/
#include <my.h>
#include <my/fast.h>

void fill_char_grid(char_grid_t *grid, char to_fill)
{
    for (int y = 0; y < grid->size_y; y++) {
        for (int x = 0; x < grid->size_x; x++) {
            grid->elements[y][x] = to_fill;
        }
    }
}

void fill_int_grid(int_grid_t *grid, int to_fill)
{
    for (int y = 0; y < grid->size_y; y++) {
        for (int x = 0; x < grid->size_x; x++) {
            grid->elements[y][x] = to_fill;
        }
    }
}