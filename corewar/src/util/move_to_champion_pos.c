/*
** EPITECH PROJECT, 2021
** move_to_champion_pos
** File description:
** Source code
*/

#include "corewar/corewar.h"

void move_to_champion_pos(program_memory_t *mem, program_memory_t *champ)
{
    mem->pos = champ->pos;
}