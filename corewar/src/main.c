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
#include <corewar/op.h>
#include <corewar/debug.h>

bool create_champion(program_memory_t *champ, program_memory_t *mem, char *file)
{
    champ->start_pos = mem->start_pos;
    champ->end_pos = mem->end_pos;
    champ->pos = mem->pos;
    if (write_file_in_memory(mem, file) == false)
        return (false);
    jump_relative_bytes(mem, 150);
    return (true);
}

int main(int ac, char *av[])
{
    char memory[4096] = {0};
    program_memory_t mem = {
        .start_pos = memory,
        .end_pos = memory + sizeof(memory),
        .pos = memory
    };
    program_memory_t champ[ac - 1];
    output_op_t op;
    int code;

    for (int i = 1; i < ac; i++)
        if (create_champion(&champ[i - 1], &mem, av[i]) == false)
            return (84);
    mem.pos = champ[0].pos;
    while (true) {
        code = *mem.pos;
        if (code == 0x00)
            break;
        OP[code].parse_bytecode(&op, &mem);
        debug_and_pause(&op, &mem);
    }
}