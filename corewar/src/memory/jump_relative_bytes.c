/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <stddef.h>
#include <my/io.h>

void jump_relative_bytes(program_memory_t *mem, ptrdiff_t increment)
{
    ptrdiff_t offset = mem->pos - mem->start_pos;
    ptrdiff_t size = mem->end_pos - mem->start_pos;

    offset += increment;
    while (offset < 0)
        offset += size;
    mem->pos = &mem->start_pos[offset % size];
}