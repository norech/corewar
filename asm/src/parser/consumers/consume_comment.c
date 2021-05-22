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

int copy_arg(char *pos, char **sv_ptr, parser_t *parser)
{
    int index = 0;

    for (; pos[0] != '"' && pos[0] != '\0'; index++) {
        if (index >= COMMENT_LENGTH)
            return (1);
        parser->header->comment[index] = pos[0];
        pos++;
    }
    *sv_ptr = pos;
    return (0);
}

int consume_comment(parser_t *parser)
{
    char *pos = parser->pos;

    if (my_strncmp(".comment", pos, 8) != 0)
        return 0;
    pos += 8;
    if (parser->header->comment[0] != '\0')
        return (parser_error(parser, MULT, ".comment"));
    for (; pos[0] != '"' && pos[0] != '\0'; pos++);
    if (pos[0] == '\0')
        return (false);
    pos++;
    if (copy_arg(pos, &pos, parser) != 0)
        return (parser_error(parser, LONG, ".comment"));
    if (pos[0] == '\0')
        return (false);
    pos++;
    parser->pos = pos;
    return (true);
}