/*
** EPITECH PROJECT, 2021
** fork
** File description:
** Source code
*/

#include "asm/parser.h"

char *get_argument_name(int i)
{
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

int check_register(instruction_t *instruction, int i)
{
    if (instruction->args[i].type == ARG_REG_ID) {
        if (instruction->args[i].reg_id < 1 ||
            instruction->args[i].reg_id > 10)
        return -1;
    }
    return 0;
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
        if (check_register(instruction, i) != 0)
            return (analyzer_error(analyzer, instruction, INVALID_REG_VALUE,
                                                                        NULL));
    }
    return (0);
}