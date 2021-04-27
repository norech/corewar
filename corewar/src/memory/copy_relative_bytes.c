/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
** File description:
** Source code
*/

#include <corewar/corewar.h>

void copy_relative_bytes(void *dest, program_memory_t *mem, size_t count)
{
    long offset = mem->pos - mem->start_pos;
    long size = mem->end_pos - mem->start_pos;
    unsigned char *dest_bytes = (unsigned char *)dest;

    for (size_t i = 0; i < count; i++) {
        dest_bytes[i] = mem->start_pos[(offset + i) % (size + 1)];
    }
}