/*
** EPITECH PROJECT, 2021
** fetch_char
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_char(char *chr_val, program_memory_t *mem)
{
    copy_relative_bytes(chr_val, mem, sizeof(char));
    jump_relative_bytes(mem, sizeof(char));
    return (0);
}