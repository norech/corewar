/*
** EPITECH PROJECT, 2021
** parser
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


int parse_next_label(instruction_t *out_instr UNUSED, parser_t *parser
    UNUSED)
{
    return (0);
}

int parse_next_instruction(instruction_t *out_instr, parser_t *parser)
{
    bool end_with_comma = true;

    consume_whitespaces(parser);
    if ((out_instr->bytecode = consume_instruction_mnemo(parser)) == 0)
        return (parser_error(parser, EXPECT_TOKEN, "mnemonic"));
    if (consume_whitespaces(parser) == 0)
        return (parser_error(parser, EXPECT_TOKEN, "space"));
    for (int i = 0; i < MAX_ARGS_NUMBER && end_with_comma; i++) {
        my_memset(&out_instr->args[i], 0, sizeof(arg_t));
        if (parse_next_argument(&out_instr->args[i], out_instr, parser) < 0)
            return (parser_error(parser, EXPECT_TOKEN, "argument"));
        if (consume_comma(parser) == 0)
            end_with_comma = false;
    }
    if (end_with_comma)
        return (parser_error(parser, INVALID_TOKEN, "','"));
    if (*parser->pos != '\0' && consume_newlines(parser) == 0)
        return (parser_error(parser, EXPECT_TOKEN, "'\\n'"));
    return (*parser->pos == '\0' ? 0 : 1);
}

int parse_program(parser_t *parser)
{
    instruction_t instr = {0};
    instruction_t *node;
    int code = 0;

    while (true) {
        while (consume_whitespaces(parser) != 0
            || consume_newlines(parser) != 0);

        if ((code = parse_next_instruction(&instr, parser)) <= 0)
            break;
        node = malloc(sizeof(instruction_t));
        if (node == NULL)
            return (parser_error(parser, ALLOC_FAILED, NULL));
        my_memcpy(node, &instr, sizeof(instruction_t));
        push_instruction(&parser->program.instructions, node);
        my_memset(&instr, 0, sizeof(instruction_t));
    }
    return (code);
}