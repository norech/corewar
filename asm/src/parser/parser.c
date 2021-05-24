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

int parse_next_instruction(instruction_t *out_instr, parser_t *parser)
{
    bool end_with_comma = true;

    consume_whitespaces(parser);
    if ((out_instr->bytecode = consume_instruction_mnemo(parser)) == 0)
        return (parser_error(parser, EXPECT_TOKEN, "mnemonic"));
    out_instr->position = parser->pos - 1;
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

int link_instructions(instruction_t *target, labels_ll_t *labels,
    label_t *new_labels)
{
    label_t *current = new_labels;
    label_t *prev = current;

    if (new_labels == NULL)
        return (0);
    while (current != NULL) {
        prev = current;
        current->target = target;
        current = current->next;
        labels->size++;
    }
    if (labels->tail == NULL) {
        labels->head = new_labels;
        labels->tail = prev;
        return (0);
    }
    new_labels->prev = labels->tail;
    labels->tail->next = new_labels;
    labels->tail = prev;
    return (0);
}

int append_instruction(instruction_t *instr, label_t *labels, parser_t *parser)
{
    instruction_t *node = malloc(sizeof(instruction_t));

    if (node == NULL)
        return (parser_error(parser, ALLOC_FAILED, NULL));
    my_memcpy(node, instr, sizeof(instruction_t));
    link_instructions(node, &parser->program.labels, labels);
    push_instruction(&parser->program.instructions, node);
    my_memset(instr, 0, sizeof(instruction_t));
    return (0);
}

int parse_program(parser_t *parser)
{
    instruction_t instr = {0};
    label_t *labels;
    int code = 0;

    while (true) {
        while (consume_whitespaces(parser) != 0
            || consume_newlines(parser) != 0);
        if ((code = get_prog_name(parser)) < 0)
            break;
        if ((code = parse_labels(&labels, parser)) < 0)
            break;
        if ((code = parse_next_instruction(&instr, parser)) < 0)
            break;
        if (append_instruction(&instr, labels, parser) < 0)
            return (-1);
        if (code == 0)
            break;
    }
    return (code);
}