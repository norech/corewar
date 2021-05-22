/*
** EPITECH PROJECT, 2021
** parser_args
** File description:
** Source code
*/
#include <my.h>
#include <my/io.h>
#include "corewar/corewar.h"
#include "corewar/op.h"
#include <asm/parser.h>
#include <asm/util.h>

static void fill_argument_body(arg_t *output_arg, char prefix, int number)
{
    if (prefix == '\0') {
        output_arg->type = ARG_IND_NB;
        output_arg->ind_val = number;
    }
    if (prefix == DIRECT_CHAR) {
        output_arg->type = ARG_DIR_NB;
        output_arg->dir_val = number;
    }
    if (prefix == 'r') {
        output_arg->type = ARG_REG_ID;
        output_arg->reg_id = number;
    }
}

int parse_next_argument(arg_t *output_arg, instruction_t *instr,
    parser_t *parser)
{
    int number;
    char *label;
    char prefix = '\0';

    consume_whitespaces(parser);
    if (*parser->pos == DIRECT_CHAR || *parser->pos == 'r')
        prefix = *(parser->pos++);
    if (consume_number(&number, parser) != 0) {
        fill_argument_body(output_arg, prefix, number);
    } else {
        if ((number = consume_arg_label(&label, parser)) <= 0)
            return (parser_error(parser, EXPECT_TOKEN, "argument value"));
        output_arg->label = my_strndup(label, number);
        if (output_arg->label == NULL)
            return (parser_error(parser, ALLOC_FAILED, NULL));
        fill_argument_body(output_arg, prefix, number);
    }
    instr->args_count++;
    consume_whitespaces(parser);
    return (0);
}