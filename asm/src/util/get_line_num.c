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

int get_line_num_parser(int *output_char_pos, parser_t *parser, char *curr_ptr)
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

int get_line_num_analyzer(int *output_char_pos, analyzer_t *analyzer,
    analyzer_error_t *curr_err)
{
    char *curr_ptr = curr_err->is_instr ? curr_err->instr->position : NULL;
    char *pos = analyzer->start;
    int line = 1;
    int char_pos = 1;

    if (!curr_err->is_instr) {
        *output_char_pos = 0;
        return (0);
    }
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