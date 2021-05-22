/*
** EPITECH PROJECT, 2021
** fill_parser
** File description:
** Source code
*/

#include <my.h>
#include "asm/parser.h"
#include "corewar/op.h"

int init_parser(parser_t *output_parser, header_t *header, char *file,
    char *input)
{
    my_memset(output_parser, 0, sizeof(parser_t));
    my_memset(header, 0, sizeof(header_t));
    header->magic = COREWAR_EXEC_MAGIC;
    output_parser->header = header;
    output_parser->filename = file;
    output_parser->pos = input;
    output_parser->start = input;
    return (0);
}