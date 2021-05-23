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

bool aff(runtime_op_t *op UNUSED, vm_t *vm UNUSED,
    program_memory_t *instance)
{
    if (op->args[0].type != ARG_REG_ID)
        return (false);
    my_printf("%c", resolve_arg_value(&op->args[0], instance, false) % 256);
    return (true);
}