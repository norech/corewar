/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
** File description:
** Source code
*/

#include <corewar/corewar.h>

void jump_relative_bytes(program_memory_t *mem, size_t increment)
{
    long offset = mem->pos - mem->start_pos;
    long size = mem->end_pos - mem->start_pos;

    offset += increment;
    while (offset < 0)
        offset += size;
    while (offset >= size)
        offset -= size;
    mem->pos = mem->start_pos + offset;
}