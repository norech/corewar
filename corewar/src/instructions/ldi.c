/*
** EPITECH PROJECT, 2021
** live
** File description:
** Source code
*/

#include "corewar/debug.h"
#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/datatype.h>
#include <corewar/memory.h>
#include <corewar/op.h>
#include <corewar/util.h>
#include <stdlib.h>

bool ldi(runtime_op_t *op UNUSED, vm_t *vm UNUSED,
    program_memory_t *instance)
{
    instance->registers[ op->args[2].reg_id - 1 ]
        = resolve_arg_index_value(&op->args[0], instance, true, false)
            + resolve_arg_index_value(&op->args[1], instance, true, false);
    if (instance->registers[op->args[2].reg_id - 1] == 0)
        instance->carry = 1;
    else
        instance->carry = 0;
    return (0);
}