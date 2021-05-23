/*
** EPITECH PROJECT, 2021
** main
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/champion.h>
#include <corewar/op.h>
#include <corewar/debug.h>
#include <corewar/parser.h>
#include <corewar/util.h>
#include <stdio.h>

static int count_args(args_t *args)
{
    int i = 1;

    for (g_args_t *arg = args->g_args; arg->next != NULL; arg = arg->next)
        i++;
    return (i);
}

static int read_args(vm_t *vm, args_t *args)
{
    int i = 1;

    vm->cycles_until_dump = args->nbr_cycle;
    vm->debug = args->debug_mode;
    for (g_args_t *arg = args->g_args; arg->next != NULL; arg = arg->next) {
        if (arg->has_load_address) {
            vm->memory.pos = vm->memory.start_pos;
            jump_relative_bytes(&vm->memory, arg->load_address);
        } else {
            jump_relative_bytes(&vm->memory, 150);
        }
        if (create_champion_from_file(&vm->champions[i - 1], &vm->memory,
            arg->name))
                return (84);
        if (arg->has_prog_number)
            vm->champions[i - 1].prog_number = arg->prog_number;
        i++;
    }
    return (0);
}

static void free_args(vm_t *vm, args_t *args)
{
    g_args_t *next;

    vm->cycles_until_dump = args->nbr_cycle;
    for (g_args_t *arg = args->g_args; arg != NULL; arg = next) {
        next = arg->next;
        free(arg);
    }
}

int main(int ac, char *av[])
{
    vm_t vm = {0};
    args_t args;

    args.nbr_cycle = 10;
    vm.cycles_until_dump = -1;
    if (args_manager(ac, av, &args) == 84 || count_args(&args) < 2)
        return (84);
    if (init_vm(&vm, count_args(&args)) < 0 || init_memory(&vm.memory) < 0)
        return (84);
    if (read_args(&vm, &args) < 0)
        return (84);
    while (true)
        if (next_step(&vm) == 1)
            break;
    free_args(&vm, &args);
    destroy_memory(&vm.memory);
    free(vm.champions);
}