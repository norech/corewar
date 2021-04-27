/*
** EPITECH PROJECT, 2021
** dump_memory
** File description:
** Source code
*/

#include <my/common.h>
#include <my/io.h>
#include <corewar/corewar.h>

void dump_memory(char *bytes, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        my_printf("%02x", bytes[i]);
        if (i % 25 == 24) {
            my_printf("\n");
        } else {
            my_printf(" ");
        }
    }
}