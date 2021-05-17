/*
** EPITECH PROJECT, 2021
** parser_error
** File description:
** Source code
*/

#include <my/str.h>
#include "corewar/corewar.h"
#include "corewar/op.h"
#include <asm/parser.h>

int parser_error(parser_t *parser, enum parser_error_code code, char *message)
{
    unsigned long i = 0;

    while (parser->errors[i].code != NO_ERROR && i < COUNTOF(parser->errors))
        i++;
    if (i < COUNTOF(parser->errors)) {
        parser->errors[i].pos = parser->pos;
        parser->errors[i].code = code;
        parser->errors[i].message = my_strdup(message);
    }
    return (-code);
}