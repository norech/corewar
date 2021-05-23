/*
** EPITECH PROJECT, 2021
** fork
** File description:
** Source code
*/

#include <my.h>
#include "asm/parser.h"
#include "corewar/op.h"

int analyze_size(analyzer_t *analyzer, instruction_t *instruction)
{
    op_t *tab_op = &OP_TAB[instruction->bytecode];
    int size = 1;

    if (HAS_CODING_BYTE(instruction->bytecode))
        size++;
    for (int i = 0; i < instruction->args_count; i++) {
        if ((instruction->args[i].type & T_REG) != 0) {
            size += 1;
            continue;
        }
        if ((tab_op->type[i] & T_IDX) != 0) {
            size += 2;
            continue;
        }
        size += 2;
        if ((instruction->args[i].type & T_DIR) != 0)
            size += 2;
    }
    instruction->byte_count = size;
    analyzer->header->prog_size += size;
    return (0);
}