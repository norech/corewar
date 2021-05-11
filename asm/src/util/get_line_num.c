/*
** EPITECH PROJECT, 2021
** main
** File description:
** Source code
*/

#include "corewar/op.h"
#include <my.h>
#include <my/io.h>
#include <asm/bytecode.h>
#include <asm/parser.h>
#include <fcntl.h>

int get_line_num(int *output_char_pos, parser_t *parser, char *curr_ptr)
{
    char *pos = parser->start;
    int line = 1;
    int char_pos = 1;

    while (pos < curr_ptr && *pos != '\0') {
        if (*pos == '\n') {
            line++;
            char_pos = 1;
        }
        char_pos++;
        pos++;
    }
    if (output_char_pos != NULL)
        *output_char_pos = char_pos;
    return (line);
}