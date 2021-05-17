/*
** EPITECH PROJECT, 2021
** fork
** File description:
** Source code
*/

#include "asm/parser.h"

char *get_argument_name(int i) {
    switch (i) {
        case 0:
            return "first argument";
        case 1:
            return "second argument";
        case 2:
            return "third argument";
        case 3:
            return "fourth argument";
        default:
            return "invalid argument";
    }
}
int analyze_signature(analyzer_t *analyzer, instruction_t *instruction)
{
    op_t *tab_op = &OP_TAB[instruction->bytecode];

    if (instruction->args_count != tab_op->args_count)
        return (analyzer_error(analyzer, instruction, INVALID_ARG_COUNT, NULL));
    for (int i = 0; i < instruction->args_count; i++) {
        if ((instruction->args[i].type & tab_op->type[i]) == 0)
            return (analyzer_error(analyzer, instruction, INVALID_ARG_TYPE,
                get_argument_name(i)));
    }
    return (0);
}