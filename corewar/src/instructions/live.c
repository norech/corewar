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
    champion_t *champ = NULL;
    int prog_number = resolve_arg_value(&op->args[0], instance);

    for (int i = 0; i < vm->champions_count; i++) {
        if (vm->champions[i].prog_number == prog_number)
            champ = &vm->champions[prog_number - 1];
    }
    if (champ == NULL)
        return (true);
    my_printf("The player %d(%s)is alive.\n", prog_number, champ->name);
    champ->cycles_since_last_live = 0;
    vm->live_calls++;
    if (vm->live_calls >= NBR_LIVE) {
        vm->live_calls = 0;
        vm->cycles_to_die -= CYCLE_DELTA;
    }
    return (true);
}