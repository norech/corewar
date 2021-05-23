/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-corewar-alexis.cheron
** File description:
** xor
*/

#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/datatype.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool xor(runtime_op_t *op UNUSED, champion_t *champ UNUSED,
    program_memory_t *instance)
{
    instance->registers[op->args[2].reg_id - 1] =
        resolve_arg_value(&op->args[0], instance, false)
            ^ resolve_arg_value(&op->args[1], instance, false);
    if (instance->registers[op->args[2].reg_id - 1] == 0)
        instance->carry = 1;
    else
        instance->carry = 0;
    return (true);
}