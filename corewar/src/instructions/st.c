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

bool st(runtime_op_t *op UNUSED, vm_t *vm UNUSED,
    program_memory_t *instance)
{
    reg_data_t data;
    int index;

    if (op->args[1].type == ARG_IND_NB) {
        index = op->args[1].ind_val % IDX_MOD;
        jump_relative_bytes(instance, index - op->bytecount);
        data = resolve_arg_value(&op->args[0], instance);
        write_relative_endian_bytes(instance, &data, REG_SIZE);
        jump_relative_bytes(instance, op->bytecount - index - REG_SIZE);
    } else {
        instance->registers[op->args[1].reg_id - 1]
            = resolve_arg_value(&op->args[0], instance);
    }
    return (0);
}