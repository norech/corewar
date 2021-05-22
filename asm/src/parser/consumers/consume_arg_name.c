/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-corewar-alexis.cheron
** File description:
** consume_arg_name
*/

#include "asm/parser.h"
#include "my/str.h"
#include "my/io.h"
#include <stdio.h>

int consume_name(parser_t *parser)
{
    char *pos = parser->pos;

    if (my_strncmp(".name", pos, 5) != 0)
        return 0;
    if (parser->header->prog_name[0] != '\0')
        return (parser_error(parser, MULT, ".name"));
    pos += 5;
    while (pos[0] != '"' && pos[0] != '\0')
        pos++;
    if (pos[0] == '\0')
        return (0);
    pos++;
    for (int index = 0; pos[0] != '"'
        && pos[0] != '\0'; index++) {
            parser->header->prog_name[index] = pos[0];
            pos++;
    }
    if (pos[0] == '\0')
        return (0);
    pos++;
    parser->pos = pos;
    return (true);
}