/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>

void copy_relative_endian_bytes(void *dest, program_memory_t *mem, size_t count)
{
    long offset = mem->pos - mem->start_pos;
    long size = mem->end_pos - mem->start_pos;
    byte_t *dest_bytes = (byte_t *)dest;

    if (is_host_big_endian()) {
        copy_relative_bytes(dest, mem, count);
        return;
    }
    for (size_t i = 0; i < count; i++) {
        dest_bytes[count - i - 1] = mem->start_pos[(offset + i) % size].data;
    }
}