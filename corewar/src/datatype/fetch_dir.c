/*
** EPITECH PROJECT, 2021
** fetch_dir
** File description:
** Source code
*/

#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_dir(dir_t *dir_val, program_memory_t *mem)
{
    copy_relative_endian_bytes(dir_val, mem, DIR_SIZE);
    jump_relative_bytes(mem, DIR_SIZE);
    return (0);
}