/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-corewar-alexis.cheron
** File description:
** distance_between_instructions
*/

#include "corewar/op.h"
#include <asm/compiler.h>
#include <unistd.h>

void get_start_and_end(size_t *start, size_t *end, int id_1, int id_2)
{
    if (id_1 < id_2) {
        *start = id_1;
        *end = id_2;
    } else {
        *start = id_2;
        *end = id_1;
    } return;
}

size_t distance_between_instructions(instruction_t *ins_1, instruction_t *ins_2)
{
    size_t distance = 0;
    size_t start = 0;
    size_t end = 0;

    get_start_and_end(&start, &end, ins_1->id, ins_2->id);
    for (; start != end; start++) {
        if (ins_1->id < ins_2->id) {
            distance += ins_1->byte_count;
            ins_1 = ins_1->next;
        } else {
            distance += ins_2->byte_count;
            ins_2 = ins_2->next;
        }
    } return distance;
}