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

int main(int ac, char *av[])
{
    vm_t vm = {0};

    vm.cycles_to_die = CYCLE_TO_DIE;
    vm.debug = true;
    vm.champions = malloc(sizeof(champion_t) * ac);
    if (vm.champions == NULL)
        return (84);
    vm.champions_count = ac - 1;
    vm.champions[ac - 1].instances = NULL;
    init_memory(&vm.memory);
    for (int i = 1; i < ac; i++) {
        if (create_champion_from_file(&vm.champions[i - 1], &vm.memory, av[i]))
            return (84);
        jump_relative_bytes(&vm.memory, 1200);
    }
    while (true)
        if (next_step(&vm) == 1)
            break;
    dump_memory(&vm.memory);
    destroy_memory(&vm.memory);
    free(vm.champions);
}