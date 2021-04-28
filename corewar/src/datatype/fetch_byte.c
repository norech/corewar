/*
** EPITECH PROJECT, 2021
** fetch_uchar
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_byte(byte_t *chr_val, program_memory_t *mem)
{
    copy_relative_bytes(chr_val, mem, sizeof(byte_t));
    jump_relative_bytes(mem, sizeof(byte_t));
    return (0);
}