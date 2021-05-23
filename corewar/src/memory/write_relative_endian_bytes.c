/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
** File description:
** Source code
*/

#include "corewar/memory.h"
#include <corewar/corewar.h>

void write_relative_endian_bytes(program_memory_t *mem, void *src, size_t count)
{

    long offset = mem->pos - mem->start_pos;
    long size = mem->end_pos - mem->start_pos;
    byte_t *src_bytes = (byte_t *)src;
    memory_slot_t *slot;
    size_t i = 0;

    if (is_host_big_endian()) {
        write_relative_bytes(mem, src, count);
        return;
    }
    for (; i < count; i++) {
        slot = &mem->start_pos[(offset + i) % size];
        slot->data = src_bytes[count - i - 1];
        slot->owner = mem->owner_id;
    }
    mem->pos += i;
}