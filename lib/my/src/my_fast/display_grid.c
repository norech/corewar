/*
** EPITECH PROJECT, 2021
** print_grid
** File description:
** Source code
*/

#include <my/types.h>
#include <my/io.h>
#include <my/fast.h>

void display_char_grid(char_grid_t *grid, enum grid_display_args flags)
{
    bool display_digits = (flags & G_DISPLAY_AS_DIGITS) != 0;
    bool has_final_newline = (flags & G_NO_FINAL_NEWLINE) == 0;
    int y;
    int x;

    for (y = 0; y < grid->size_y - 1; y++) {
        for (x = 0; x < grid->size_x; x++) {
            my_printf(display_digits ? "%d" : "%c", grid->elements[y][x]);
        }
        my_printf("\n");
    }
    for (x = 0; x < grid->size_x; x++) {
        my_printf(display_digits ? "%d" : "%c", grid->elements[y][x]);
    }
    if (has_final_newline)
        my_printf("\n");
}

void display_int_grid(int_grid_t *grid, enum grid_display_args flags)
{
    bool display_digits = (flags & G_DISPLAY_AS_DIGITS) != 0;
    bool has_final_newline = (flags & G_NO_FINAL_NEWLINE) == 0;
    int y;
    int x;

    for (y = 0; y < grid->size_y - 1; y++) {
        for (x = 0; x < grid->size_x; x++) {
            my_printf(display_digits ? "%d" : "%c", grid->elements[y][x]);
        }
        my_printf("\n");
    }
    for (x = 0; x < grid->size_x; x++) {
        my_printf(display_digits ? "%d" : "%c", grid->elements[y][x]);
    }
    if (has_final_newline)
        my_printf("\n");
}