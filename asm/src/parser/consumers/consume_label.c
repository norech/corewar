/*
** EPITECH PROJECT, 2021
** consume_label
** File description:
** Source code
*/

#include "asm/parser.h"
#include <my/str.h>
#include <my/io.h>
#include <corewar/op.h>

int consume_label(char **output_label, parser_t *parser)
{
    char *pos = parser->pos;
    int i = 0;

    while (my_char_in(LABEL_CHARS, *pos)) {
        pos++;
        i++;
    }
    if (*pos != LABEL_CHAR)
        return (0);
    pos++;
    *output_label = parser->pos;
    parser->pos = pos;
    return (i);
}