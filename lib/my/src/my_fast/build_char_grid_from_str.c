/*
** EPITECH PROJECT, 2021
** build_char_grid_from_str
** File description:
** Source code
*/
#include <my/fast.h>
#include <my/io.h>

static int fill_char_grid_from_str(char_grid_t *output, char *str,
    size_t expected_size_x, size_t expected_size_y)
{
    size_t i;
    size_t x = 0;
    size_t y = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] == '\0')
            break;
        if (str[i] == '\n') {
            if (x != expected_size_x)
                return (BAD_SIZE_ERROR);
            x = 0;
            y++;
        } else {
            output->elements[y][x] = str[i];
            x++;
        }
    }
    if (x != expected_size_x || y != expected_size_y - 1)
        return (BAD_SIZE_ERROR);
    return (0);
}

int build_char_grid_from_str(char_grid_t **output, char *str)
{
    size_t size_x = count_line_len(str);
    size_t size_y = count_lines(str, true);

    *output = create_char_grid(size_x, size_y);
    if (*output == NULL)
        return (MALLOC_ERROR);
    return (fill_char_grid_from_str(*output, str, size_x, size_y));
}