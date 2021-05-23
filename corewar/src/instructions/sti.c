/*
** EPITECH PROJECT, 2021
** sti
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

bool sti(runtime_op_t *op UNUSED, vm_t *vm UNUSED,
    program_memory_t *instance)
{
    reg_data_t data;
    int index = (resolve_arg_index_value(&op->args[1], instance)
        + resolve_arg_index_value(&op->args[2], instance)) % IDX_MOD;

    jump_relative_bytes(instance, index - op->bytecount);
    data = resolve_arg_value(&op->args[0], instance);
    write_relative_endian_bytes(instance, &data, REG_SIZE);
    jump_relative_bytes(instance, op->bytecount - index - REG_SIZE);
    return (0);
}