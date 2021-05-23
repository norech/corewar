/*
** EPITECH PROJECT, 2021
** init_vm
** File description:
** Source code
*/

#include "corewar/op.h"
#include "corewar/memory.h"
#include "corewar/util.h"

int init_vm(vm_t *vm, int champions_count)
{
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->debug = true;
    vm->champions = malloc(sizeof(champion_t) * (champions_count + 1));
    if (vm->champions == NULL)
        return (-1);
    vm->champions_count = champions_count;
    vm->champions[champions_count].instances = NULL;
    if (init_memory(&vm->memory) < 0)
        return (-1);
    return (0);
}