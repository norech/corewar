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

int consume_arg_label(char **output_label, parser_t *parser)
{
    int i = 0;

    if (*parser->pos != LABEL_CHAR)
        return (0);
    parser->pos++;
    if (*parser->pos == '\0' || !my_char_in(LABEL_CHARS, *parser->pos))
        return (parser_error(parser, EXPECT_TOKEN, "label name"));
    *output_label = parser->pos;
    while (my_char_in(LABEL_CHARS, *parser->pos)) {
        parser->pos++;
        i++;
    }
    return (i);
}