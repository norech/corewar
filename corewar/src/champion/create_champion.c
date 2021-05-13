/*
** EPITECH PROJECT, 2021
** create_champion
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

static int init_instance(program_memory_t *champ_inst, program_memory_t *mem,
    memory_slot_t *first_instruction_pos)
{
    program_memory_t champ_mem = {
        .start_pos = mem->start_pos,
        .end_pos = mem->end_pos,
        .pos = first_instruction_pos,
        .owner_id = mem->owner_id
    };

    my_memcpy(champ_inst, &champ_mem, sizeof(champ_mem));
    my_memset(mem->registers, 0, sizeof(mem->registers));
    return (0);
}

int create_champion(champion_t *champ, program_memory_t *mem)
{
    memory_slot_t *first_instruction_pos = mem->pos;

    mem->owner_id++;
    champ->id = mem->owner_id;
    champ->instances_max = 10;
    champ->instances = malloc(sizeof(program_memory_t) * champ->instances_max);
    if (champ->instances == NULL)
        return (-1);
    champ->instances_count = 1;
    init_instance(&champ->instances[0], mem, first_instruction_pos);
    champ->instances[0].registers[0] = mem->owner_id;
    return (0);
}

int create_champion_from_file(champion_t *champ, program_memory_t *mem,
    char *file)
{
    if (create_champion(champ, mem) < 0)
        return (-1);
    load_champion_from_file(champ, file);
    return (0);
}