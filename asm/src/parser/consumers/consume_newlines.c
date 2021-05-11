/*
** EPITECH PROJECT, 2021
** consume_newline
** File description:
** Source code
*/

#include "asm/parser.h"

int consume_newlines(parser_t *parser)
{
    int i = 0;

    while (*parser->pos == '\n' || *parser->pos == '\r') {
        parser->pos++;
        if (*parser->pos != '\r')
            i++;
    }
    return (i);
}