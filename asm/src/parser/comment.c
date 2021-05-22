/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-corewar-alexis.cheron
** File description:
** comment
*/

#include "corewar/op.h"
#include <my.h>
#include <my/io.h>
#include <asm/bytecode.h>
#include <asm/parser.h>
#include <asm/util.h>
#include <fcntl.h>
#include <stdio.h>

int get_prog_name(parser_t *parser)
{
    int code_one;
    int code_two;

    while ((code_one = consume_name(parser)) != 0
        || (code_two = consume_comment(parser)) != 0) {
            if (code_one < 0)
                return (code_one);
            if (code_two < 0)
                return (code_two);
            if (*parser->pos != '\0' && consume_newlines(parser) == 0)
                return (parser_error(parser, EXPECT_TOKEN, "'\\n'"));
            while (consume_whitespaces(parser) != 0
                    || consume_newlines(parser) != 0);
    }
    return (0);
}