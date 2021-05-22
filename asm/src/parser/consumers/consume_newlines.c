/*
** EPITECH PROJECT, 2021
** consume_newline
** File description:
** Source code
*/

#include "asm/parser.h"

void consume_commentary(parser_t *parser)
{
    if (*parser->pos == '#')
        do {
            parser->pos++;
        } while (*parser->pos != '\n' && *parser->pos != '\r'
            && *parser->pos != '\0');
}

int consume_newlines(parser_t *parser)
{
    int i = 0;

    consume_commentary(parser);
    while (*parser->pos == '\n' || *parser->pos == '\r') {
        parser->pos++;
        consume_commentary(parser);
        if (*parser->pos != '\r')
            i++;
    }
    return (i);
}