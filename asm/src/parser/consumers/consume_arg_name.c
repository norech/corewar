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

static int copy_arg(char *pos, char **sv_ptr, parser_t *parser)
{
    int index = 0;

    for (; pos[0] != '"' && pos[0] != '\0'; index++) {
        if (index >= PROG_NAME_LENGTH)
            return (1);
        parser->header->prog_name[index] = pos[0];
        pos++;
    }
    *sv_ptr = pos;
    return (0);
}

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
    if (copy_arg(pos, &pos, parser) != 0)
        return (parser_error(parser, LONG, ".name"));
    if (pos[0] == '\0')
        return (0);
    pos++;
    parser->pos = pos;
    return (true);
}