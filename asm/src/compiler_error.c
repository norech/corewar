/*
** EPITECH PROJECT, 2021
** compiler_error
** File description:
** Source code
*/

#include "corewar/op.h"
#include <my.h>
#include <my/io.h>
#include <asm/bytecode.h>
#include <asm/parser.h>
#include <asm/util.h>
#include <fcntl.h>

static void show_error(parser_t *parser, parser_error_t *error)
{
    int char_pos = 1;
    int line = get_line_num(&char_pos, parser, error->pos);

    my_dprintf(2, "%s:%d:%d: ", parser->filename, line, char_pos);
    switch (error->code) {
        case ALLOC_FAILED:
            my_dprintf(2, "Malloc failed\n");
            break;
        case EXPECT_TOKEN:
            my_dprintf(2, "Expected %s, found '%c'\n", error->message,
                *error->pos);
            break;
        case INVALID_TOKEN:
            my_dprintf(2, "Invalid token: %s\n", error->message);
            break;
        case NO_ERROR:
            break;
    }
}

void show_errors(parser_t *parser)
{
    unsigned long i = 0;

    while (parser->errors[i].code != NO_ERROR && i < COUNTOF(parser->errors)) {
        show_error(parser, &parser->errors[i]);
        i++;
    }
}