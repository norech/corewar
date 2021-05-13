/*
** EPITECH PROJECT, 2021
** fill_parser
** File description:
** Source code
*/

#include <my.h>
#include "asm/parser.h"

int init_parser(parser_t *output_parser, char *file, char *input)
{
    my_memset(output_parser, 0, sizeof(parser_t));
    output_parser->filename = file;
    output_parser->pos = input;
    output_parser->start = input;
    return (0);
}