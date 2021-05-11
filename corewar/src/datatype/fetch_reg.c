/*
** EPITECH PROJECT, 2021
** fetch_reg
** File description:
** Source code
*/

#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_reg_id(reg_id_t *reg_id, program_memory_t *mem)
{
    copy_relative_endian_bytes(reg_id, mem, 1);
    jump_relative_bytes(mem, 1);
    return (0);
}