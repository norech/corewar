/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
** File description:
** Source code
*/

#include <corewar/corewar.h>

void write_relative_bytes(program_memory_t *mem, void *src, size_t count)
{
    long offset = mem->pos - mem->start_pos;
    long size = mem->end_pos - mem->start_pos;
    unsigned char *src_bytes = (unsigned char *)src;
    size_t i = 0;

    for (; i < count; i++) {
        mem->start_pos[(offset + i) % (size + 1)] = src_bytes[i];
    }
    mem->pos += i;
}