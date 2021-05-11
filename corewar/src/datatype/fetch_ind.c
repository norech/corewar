/*
** EPITECH PROJECT, 2021
** fetch_ind
** File description:
** Source code
*/

#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_ind(ind_t *ind_val, program_memory_t *mem)
{
    copy_relative_endian_bytes(ind_val, mem, IND_SIZE);
    jump_relative_bytes(mem, IND_SIZE);
    return (0);
}