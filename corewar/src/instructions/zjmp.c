/*
** EPITECH PROJECT, 2021
** zjmp
** File description:
** Source code
*/

#include <my.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool zjmp(runtime_op_t *op, champion_t *champ UNUSED,
    program_memory_t *instance)
{
    if (instance->carry == true)
        jump_relative_bytes(instance,
            op->args[0].dir_val % IDX_MOD - op->bytecount);
    return (true);
}

