/*
** EPITECH PROJECT, 2021
** init_memory
** File description:
** Source code
*/

#include "corewar/corewar.h"
#include <my.h>

int init_memory(program_memory_t *mem)
{
    memory_slot_t *memory = my_calloc(MEM_SIZE, sizeof(memory_slot_t));

    if (memory == NULL)
        return (-1);
    my_memset(mem, 0, sizeof(program_memory_t));
    mem->start_pos = memory;
    mem->end_pos = memory + MEM_SIZE;
    mem->pos = memory + MEM_SIZE - 1019;
    return (0);
}

void destroy_memory(program_memory_t *mem)
{
    free(mem->start_pos);
}