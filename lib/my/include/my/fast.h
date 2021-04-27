/*
** EPITECH PROJECT, 2021
** fast
** File description:
** Source code
*/

#ifndef CE9FFC0E_91C1_45D5_A195_42BE4A78564E
#define CE9FFC0E_91C1_45D5_A195_42BE4A78564E

#include <my.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum fast_error_codes {
    STAT_ERROR = -1,
    READ_ERROR = -2,
    MALLOC_ERROR = -3,
    BAD_SIZE_ERROR = -4
};

enum grid_display_args {
    G_DISPLAY_AS_DIGITS = 1,
    G_NO_FINAL_NEWLINE = 1 << 1
};

typedef struct char_grid_s {
    char **elements;
    int size_x;
    int size_y;
} char_grid_t;

typedef struct int_grid_s {
    int **elements;
    int size_x;
    int size_y;
} int_grid_t;

char *get_error_message(int code);

char **create_2d_char_arr(int x, int y);

char_grid_t *create_char_grid(int x, int y);

int **create_2d_int_arr(int x, int y);

int_grid_t *create_int_grid(int x, int y);

void fill_char_grid(char_grid_t *grid, char to_fill);

void fill_int_grid(int_grid_t *grid, int to_fill);

void display_char_grid(char_grid_t *grid, enum grid_display_args args);

void display_int_grid(int_grid_t *grid, enum grid_display_args args);

void destroy_char_grid(char_grid_t *grid);

void destroy_int_grid(int_grid_t *grid);

intmax_t file_get_contents(char **output, char *file, int open_flag);

size_t count_lines(char *str, bool ignore_trailing_line);

size_t count_line_len(char *str);

int build_char_grid_from_str(char_grid_t **output, char *str);

#endif /* CE9FFC0E_91C1_45D5_A195_42BE4A78564E */
