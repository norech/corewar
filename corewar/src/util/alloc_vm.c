/*
** EPITECH PROJECT, 2021
** alloc_memory
** File description:
** Source code
*/

#include <my.h>
#include "corewar/champion.h"
#include "corewar/corewar.h"
#include "corewar/memory.h"
#include "corewar/util.h"
#include <stdlib.h>

vm_t *alloc_vm(int champions_count)
{
    vm_t *vm = my_calloc(1, sizeof(vm_t));

    if (!vm)
        return (NULL);
    if (init_vm(vm, champions_count) < 0)
        return (NULL);
    vm->champions_count = 0;
    return (vm);
}

int push_champion_with_bytecode(vm_t *vm, byte_t *bytecode, int size)
{
    if (load_champion_from_bytes(&vm->champions[vm->champions_count++],
        bytecode, size) < 0)
            return (-1);
    return (0);
}

void free_vm(vm_t *vm)
{
    free(vm->champions);
    free(vm);
}