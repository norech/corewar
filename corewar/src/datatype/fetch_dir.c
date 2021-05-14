/*
** EPITECH PROJECT, 2021
** fetch_dir
** File description:
** Source code
*/

#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_dir(dir_t *dir_val, program_memory_t *mem, bool is_index)
{
    int size = is_index ? IND_SIZE : DIR_SIZE;

    copy_relative_endian_bytes(dir_val, mem, size);
    jump_relative_bytes(mem, size);
    return (0);
}