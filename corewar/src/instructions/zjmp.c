/*
** EPITECH PROJECT, 2021
** zjmp
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool zjmp(runtime_op_t *op, program_memory_t *mem)
{
    if (mem->carry == true)
        jump_relative_bytes(mem, op->args[0].dir_val % IDX_MOD - op->bytecount);
    return (true);
}

