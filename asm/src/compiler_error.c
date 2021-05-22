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

static void show_parser_error(parser_t *parser, parser_error_t *error)
{
    int char_pos = 1;
    int line = get_line_num_parser(&char_pos, parser, error->pos);
    error_parser_t err_struct[5] = {
        {EXPECT_TOKEN, "Expected %s, found '%c'\n"},
        {INVALID_TOKEN, "Invalid token: %s\n"},
        {MULT, "Multiple definition of %s\n"}, {LONG, "%s too long\n"},
        {ALLOC_FAILED, "Malloc failed\n"}
    };

    my_dprintf(2, "%s:%d:%d: ", parser->filename, line, char_pos);
    for (int i = 0; i != 4; i++) {
        if (err_struct[i].error_code == error->code) {
            my_dprintf(2, err_struct[i].format, error->message, error->pos[0]);
            return;
        }
    }
}

static void show_analyzer_error(analyzer_t *parser, analyzer_error_t *error)
{
    int char_pos = 1;
    int line = get_line_num_analyzer(&char_pos, parser, error);

    my_dprintf(2, "%s:%d:%d: ", parser->filename, line, char_pos);
    if (error->is_instr && !IS_INVALID_OP(error->instr->bytecode))
        my_dprintf(2, "Near '%s': ", OP_TAB[error->instr->bytecode].mnemo);
    switch (error->code) {
        case INVALID_ARG_COUNT:
            my_dprintf(2, "Invalid arguments count.\n");
            break;
        case INVALID_ARG_TYPE:
            my_dprintf(2, "Invalid arg type for %s.\n", error->message);
            break;
        case INVALID_REG_VALUE:
            my_dprintf(2, "Invalid reg value. Value should be 1>$value<10\n");
            break;
        case INVALID_TARGET_LABEL:
            my_dprintf(2, "Invalid target label: %s.\n", error->message);
            break;
        default:
        case NO_ANALYZER_ERROR:
            break;
    }
}

void show_parser_errors(parser_t *parser)
{
    unsigned long i = 0;

    while (parser->errors[i].code != NO_ERROR && i < COUNTOF(parser->errors)) {
        show_parser_error(parser, &parser->errors[i]);
        i++;
    }
}

void show_analyzer_errors(analyzer_t *analyzer)
{
    unsigned long i = 0;

    while (analyzer->errors[i].code != NO_ANALYZER_ERROR
            && i < COUNTOF(analyzer->errors)) {
        show_analyzer_error(analyzer, &analyzer->errors[i]);
        i++;
    }
}