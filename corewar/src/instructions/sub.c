/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-corewar-alexis.cheron
** File description:
** sub
*/

#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/datatype.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool sub(runtime_op_t *op UNUSED, champion_t *champ UNUSED,
    program_memory_t *instance)
{
    instance->registers[op->args[2].reg_id - 1] =
        instance->registers[op->args[0].reg_id - 1]
            - instance->registers[op->args[1].reg_id - 1];
    if (instance->registers[op->args[2].reg_id - 1] == 0)
        instance->carry = 1;
    else
        instance->carry = 0;
    return (true);
}