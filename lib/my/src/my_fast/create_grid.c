/*
** EPITECH PROJECT, 2021
** create_grid
** File description:
** Source code
*/

#include <stdlib.h>
#include <my/common.h>
#include <my/fast.h>

char **create_2d_char_arr(int x, int y)
{
    char **grid = malloc(sizeof(char *) * (y + 1));

    if (grid == NULL)
        return (NULL);
    for (int i = 0; i < y; i++) {
        grid[i] = my_calloc(x + 1, sizeof(char));
        if (grid[i] == NULL)
            return (NULL);
    }
    grid[y] = NULL;
    return (grid);
}

char_grid_t *create_char_grid(int x, int y)
{
    char_grid_t *grid = malloc(sizeof(char_grid_t));

    if (grid == NULL)
        return (NULL);
    grid->size_x = x;
    grid->size_y = y;
    grid->elements = create_2d_char_arr(x, y);
    if (grid->elements == NULL)
        return (NULL);
    return (grid);
}

int **create_2d_int_arr(int x, int y)
{
    int **grid = malloc(sizeof(int *) * (y + 1));

    if (grid == NULL)
        return (NULL);
    for (int i = 0; i < y; i++) {
        grid[i] = my_calloc(x + 1, sizeof(int));
        if (grid[i] == NULL)
            return (NULL);
    }
    grid[y] = NULL;
    return (grid);
}

int_grid_t *create_int_grid(int x, int y)
{
    int_grid_t *grid = malloc(sizeof(int_grid_t));

    if (grid == NULL)
        return (NULL);
    grid->size_x = x;
    grid->size_y = y;
    grid->elements = create_2d_int_arr(x, y);
    if (grid->elements == NULL)
        return (NULL);
    return (grid);
}