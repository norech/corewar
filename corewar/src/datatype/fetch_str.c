/*
** EPITECH PROJECT, 2021
** fetch_uchar
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>

int fetch_str(char **str_val, program_memory_t *mem)
{
    int len;

    copy_relative_bytes(&len, mem, sizeof(int));
    jump_relative_bytes(mem, sizeof(int));
    *str_val = malloc(sizeof(char) * (len + 1));
    copy_relative_bytes(*str_val, mem, len);
    (*str_val)[len] = '\0';
    jump_relative_bytes(mem, len);
    return (len);
}