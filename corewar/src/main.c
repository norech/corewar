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
    program_memory_t mem;
    champion_t champ[ac];
    args_t args;

    if (args_manager(ac, av, &args) == 84)
        return (84);
    champ[ac - 1].instances = NULL;
    init_memory(&mem);
    for (int i = 1; i < ac; i++) {
        if (create_champion_from_file(&champ[i - 1], &mem, av[i]))
            return (84);
        jump_relative_bytes(&mem, 1200);
    }
    mem.pos = champ[0].instances[0].pos;
    while (true) {
        next_step(&mem, champ);
    }
    destroy_memory(&mem, &args);
}