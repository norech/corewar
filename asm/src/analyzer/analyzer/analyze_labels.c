/*
** EPITECH PROJECT, 2021
** analyze_labels
** File description:
** Source code
*/

#include <my/str.h>
#include <my/io.h>
#include "asm/parser.h"
#include "asm/util.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

instruction_t *get_label_target(analyzer_t *analyzer, char *label)
{
    labels_ll_t *labels = &analyzer->program.labels;
    label_t *cur = labels->head;
    int i;

    while (cur != NULL) {
        for (i = 0; my_char_in(LABEL_CHARS, cur->label[i]); i++) {
            if (cur->label[i] != label[i] && label[i] != '\0') {
                break;
            }
        }
        if (label[i] != '\0') {
            cur = cur->next;
            continue;
        }
        return (cur->target);
    }
    return (NULL);
}

int analyze_arg_labels(analyzer_t *analyzer, instruction_t *instruction)
{
    instruction_t *target;

    for (int i = 0; i < instruction->args_count; i++) {
        if (instruction->args[i].label == NULL)
            continue;
        target = get_label_target(analyzer, instruction->args[i].label);
        if (target == NULL)
            return (analyzer_error(analyzer, instruction,
                INVALID_TARGET_LABEL, instruction->args[i].label));
        if (instruction->args[i].type == ARG_DIR_NB)
            instruction->args[i].dir_val
                = distance_between_instructions(instruction, target);
        if (instruction->args[i].type == ARG_IND_NB)
            instruction->args[i].ind_val
                = distance_between_instructions(instruction, target);
        if (instruction->args[i].type == ARG_REG_ID)
            return (analyzer_error(analyzer, instruction,
                INVALID_REG_VALUE, "label"));
    }
    return (0);
}