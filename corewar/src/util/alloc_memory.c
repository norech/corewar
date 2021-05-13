/*
** EPITECH PROJECT, 2021
** alloc_memory
** File description:
** Source code
*/

#include "corewar/corewar.h"
#include "corewar/memory.h"
#include "corewar/util.h"
#include <stdlib.h>

program_memory_t *alloc_program_memory(void)
{
    program_memory_t *mem = malloc(sizeof(program_memory_t));

    if (!mem)
        return (NULL);
    init_memory(mem);
    return (mem);
}

void free_program_memory(program_memory_t *mem)
{
    destroy_memory(mem);
    free(mem);
}

champion_t *alloc_champion(void)
{
    return (malloc(sizeof(champion_t)));
}

void free_champion(champion_t *champ)
{
    free(champ);
}