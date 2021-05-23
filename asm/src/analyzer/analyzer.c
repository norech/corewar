/*
** EPITECH PROJECT, 2021
** analyzer
** File description:
** Source code
*/

#include "asm/parser.h"
#include "asm/analyzer.h"

int analyze_program(analyzer_t *analyzer)
{
    instructions_ll_t *instr = &analyzer->program.instructions;
    int code = 0;

    for (instruction_t *node = instr->head; node != NULL; node = node->next) {
        if (analyze_signature(analyzer, node) < 0)
            return (-1);
        if (analyze_size(analyzer, node) < 0)
            return (-1);
    }
    for (instruction_t *node = instr->head; node != NULL; node = node->next) {
        if (analyze_arg_labels(analyzer, node) < 0)
            return (-1);
    }
    return (code);
}