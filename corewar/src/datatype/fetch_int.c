/*
** EPITECH PROJECT, 2021
** fetch_int
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_int(int *int_val, program_memory_t *mem)
{
    copy_relative_bytes(int_val, mem, sizeof(int));
    jump_relative_bytes(mem, sizeof(int));
    return (0);
}