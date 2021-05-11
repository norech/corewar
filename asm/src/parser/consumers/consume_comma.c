/*
** EPITECH PROJECT, 2021
** consume_comma
** File description:
** Source code
*/

#include "asm/parser.h"

int consume_comma(parser_t *parser)
{
    int i = 0;

    if (*parser->pos == ',') {
        parser->pos++;
        i++;
    }
    return (i);
}