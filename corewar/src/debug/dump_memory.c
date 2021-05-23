/*
** EPITECH PROJECT, 2021
** dump_memory
** File description:
** Source code
*/

#include <my/common.h>
#include <my/io.h>
#include <corewar/corewar.h>

void dump_memory(program_memory_t *mem)
{
    size_t len = mem->end_pos - mem->start_pos;

    for (size_t i = 0; i < len; i++) {
        if (my_ucharlen(mem->start_pos[i].data, 16) < 2)
            my_printf("0");
        my_printf("%x", mem->start_pos[i].data);
        if (i % 32 == 31) {
            my_printf("\n");
        } else {
            my_printf(" ");
        }
    }
}