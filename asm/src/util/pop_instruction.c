/*
** EPITECH PROJECT, 2021
** pop_instruction
** File description:
** Source code
*/

#include "asm/parser.h"

int pop_instruction(instructions_ll_t *list, instruction_t *instr)
{
    instruction_t *old_tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return (0);
    }
    old_tail = list->tail;
    list->tail = instr->prev;
    list->tail->next = NULL;
    list->size--;
    free(old_tail);
    return (0);
}