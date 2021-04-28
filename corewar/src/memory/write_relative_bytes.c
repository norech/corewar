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
    byte_t *src_bytes = (byte_t *)src;
    memory_slot_t *slot;
    size_t i = 0;

    for (; i < count; i++) {
        slot = &mem->start_pos[(offset + i) % size];
        slot->data = src_bytes[i];
        slot->owner = mem->owner_id;
    }
    mem->pos += i;
}