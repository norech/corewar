/*
** EPITECH PROJECT, 2021
** zjmp
** File description:
** Source code
*/

#include "corewar/datatype.h"
#include <my.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool zjmp(runtime_op_t *op, champion_t *champ UNUSED,
    program_memory_t *instance)
{
    if (instance->carry == true)
        jump_relative_bytes(instance,
            resolve_arg_index_value(&op->args[0],
                instance, true, true) - op->bytecount);
    return (true);
}

