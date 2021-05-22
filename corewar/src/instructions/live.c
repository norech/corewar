/*
** EPITECH PROJECT, 2021
** live
** File description:
** Source code
*/

#include "corewar/datatype.h"
#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool live(runtime_op_t *op UNUSED, vm_t *vm,
    program_memory_t *instance)
{
    champion_t *champ;
    int champion_id = resolve_arg_value(&op->args[0], instance);

    if (champion_id <= 0 || champion_id > vm->champions_count)
        return (true);
    champ = &vm->champions[champion_id - 1];
    my_printf("The player %d(%s)is alive.\n", champion_id, champ->name);
    return (true);
}