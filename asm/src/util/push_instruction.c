/*
** EPITECH PROJECT, 2021
** push_instruction
** File description:
** Source code
*/

#include "asm/parser.h"
#include "my/io.h"

int push_instruction(instructions_ll_t *list, instruction_t *instr)
{
    instruction_t *old_tail;

    if (list->head == NULL) {
        list->head = instr;
        list->tail = instr;
        list->size = 1;
        instr->id = 0;
        return (0);
    }
    list->tail->next = instr;
    old_tail = list->tail;
    list->tail = instr;
    list->tail->prev = old_tail;
    instr->id = list->size;
    list->size++;
    return (0);
}