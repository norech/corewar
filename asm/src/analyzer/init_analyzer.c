/*
** EPITECH PROJECT, 2021
** fill_parser
** File description:
** Source code
*/

#include <my.h>
#include "asm/parser.h"

int init_analyzer(analyzer_t *output_analyzer, parser_t *parser)
{
    my_memset(output_analyzer, 0, sizeof(parser_t));
    output_analyzer->start = parser->start;
    output_analyzer->filename = parser->filename;
    output_analyzer->program = parser->program;
    return (0);
}