/*
** EPITECH PROJECT, 2021
** fetch_uchar
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_uchar(unsigned char *chr_val, program_memory_t *mem)
{
    copy_relative_bytes(chr_val, mem, sizeof(unsigned char));
    jump_relative_bytes(mem, sizeof(unsigned char));
    return (0);
}