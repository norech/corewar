/*
** EPITECH PROJECT, 2021
** consume_whitespace
** File description:
** Source code
*/

#include "asm/parser.h"

int consume_whitespaces(parser_t *parser)
{
    int i = 0;

    while (*parser->pos == ' ' || *parser->pos == '\t') {
        parser->pos++;
        i++;
    }
    return (i);
}