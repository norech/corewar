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

int main(int ac, char *av[])
{
    vm_t vm = {0};
    args_t args;
    int i = 1;

    args.nbr_cycle = 10;
    if (args_manager(ac, av, &args) == 84)
        return (84);
    vm.cycles_until_dump = args.nbr_cycle;
    if (init_vm(&vm, count_args(&args)) < 0 || init_memory(&vm.memory) < 0)
        return (84);
    for (g_args_t *arg = args.g_args; arg->next != NULL; arg = arg->next) {

        if (arg->has_load_address) {
            vm.memory.pos = vm.memory.start_pos;
            jump_relative_bytes(&vm.memory, arg->load_address);
        } else {
            jump_relative_bytes(&vm.memory, 150);
        }
        if (create_champion_from_file(&vm.champions[i - 1], &vm.memory,
            arg->name))
                return (84);
        if (arg->has_prog_number)
            vm.champions[i - 1].prog_number = arg->prog_number;
        i++;

    }
    while (true)
        if (next_step(&vm) == 1)
            break;
    dump_memory(&vm.memory);
    destroy_memory(&vm.memory);
    free(vm.champions);
}