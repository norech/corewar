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
#include <corewar/parser.h>

bool create_champion(program_memory_t *champ, program_memory_t *mem, char *file)
{
    mem->owner_id++;
    champ->start_pos = mem->start_pos;
    champ->end_pos = mem->end_pos;
    champ->pos = mem->pos;
    champ->owner_id = mem->owner_id;
    my_memset(mem->registers, 0, sizeof(mem->registers));
    mem->registers[0] = mem->owner_id;
    if (write_file_in_memory(mem, file) == false)
        return (false);
    jump_relative_bytes(mem, 150);
    return (true);
}

int main(int ac, char *av[])
{
    memory_slot_t *memory = my_calloc(MEM_SIZE, sizeof(memory_slot_t));
    program_memory_t mem = {
        .start_pos = memory,
        .end_pos = memory + MEM_SIZE,
        .pos = memory + MEM_SIZE - 1019
    };
    program_memory_t champ[ac - 1];
    runtime_op_t op;

    for (int i = 1; i < ac; i++)
        if (create_champion(&champ[i - 1], &mem, av[i]) == false)
            return (84);
    mem.pos = champ[0].pos;
    while (true) {
        parse_bytecode(&op, &mem);
        debug_and_pause(&op, &mem);
    }
}