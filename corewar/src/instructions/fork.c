/*
** EPITECH PROJECT, 2021
** live
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/datatype.h>
#include <corewar/memory.h>
#include <corewar/op.h>
#include <corewar/util.h>
#include <stdlib.h>

bool fork_op(runtime_op_t *op UNUSED, vm_t *vm UNUSED,
    program_memory_t *instance)
{
    program_memory_t forked_instance;

    if (op->args[0].type != ARG_DIR_NB)
        return (false);
    my_memcpy(&forked_instance, instance, sizeof(program_memory_t));
    jump_relative_bytes(&forked_instance,
        (op->args[0].dir_val % IDX_MOD) - op->bytecount);
    if (append_instance(&vm->champions[instance->owner_id - 1],
        &forked_instance) < 0)
            return (false);
    return (true);
}