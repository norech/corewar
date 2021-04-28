/*
** EPITECH PROJECT, 2021
** tests
** File description:
** Source code
*/

#ifndef B3BC1A4F_742F_4A99_919E_8BDF93335B20
#define B3BC1A4F_742F_4A99_919E_8BDF93335B20

#include <my/common.h>
#include "corewar/corewar.h"

static inline program_memory_t *t_create_program_memory(size_t size)
{
    memory_slot_t *slots = my_calloc(size, sizeof(memory_slot_t));
    program_memory_t *mem = my_calloc(1, sizeof(program_memory_t));

    if (mem == NULL)
        return (NULL);
    mem->start_pos = slots;
    mem->end_pos = slots + size;
    mem->pos = slots;
    return (mem);
}

static inline void t_set_bytes_data(program_memory_t *mem, void *data,
    size_t size)
{
    byte_t *bytes = (byte_t *)data;
    for (size_t i = 0; i < size; i++) {
        mem->start_pos[i].data = bytes[i];
    }
}

static inline void t_set_bytes_owner(program_memory_t *mem, char *owners,
    size_t size)
{
    byte_t *bytes = (byte_t *)owners;
    for (size_t i = 0; i < size; i++) {
        mem->start_pos[i].owner = bytes[i];
    }
}

static inline void t_fill_bytes_data(program_memory_t *mem,
    byte_t data, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        mem->start_pos[i].data = data;
    }
}

static inline void t_fill_bytes_owner(program_memory_t *mem,
    byte_t owner_id, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        mem->start_pos[i].owner = owner_id;
    }
}

#endif /* B3BC1A4F_742F_4A99_919E_8BDF93335B20 */
