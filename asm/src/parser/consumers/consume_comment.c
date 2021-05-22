/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-corewar-alexis.cheron
** File description:
** consume_comment
*/

#include "asm/parser.h"
#include "my/str.h"
#include "my/io.h"
#include <stdio.h>

int consume_comment(parser_t *parser)
{
    char *pos = parser->pos;

    if (my_strncmp(".comment", pos, 8) != 0)
        return 0;
    pos += 8;
    if (parser->header->comment[0] != '\0')
        return (parser_error(parser, MULT, ".comment"));
    while (pos[0] != '"' && pos[0] != '\0')
        pos++;
    if (pos[0] == '\0')
        return (false);
    pos++;
    for (int index = 0; pos[0] != '"'
        && pos[0] != '\0'; index++) {
            parser->header->comment[index] = pos[0];
            pos++;
    }
    if (pos[0] == '\0')
        return (false);
    pos++;
    parser->pos = pos;
    return (true);
}