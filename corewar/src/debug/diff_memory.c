/*
** EPITECH PROJECT, 2021
** dump_memory
** File description:
** Source code
*/

#include <my/common.h>
#include <my/io.h>
#include <corewar/corewar.h>

void diff_memory(byte_t *old, byte_t *new, size_t len)
{
    byte_t old_byte;
    byte_t new_byte;

    for (size_t i = 0; i < len; i++) {
        old_byte = old[i];
        new_byte = new[i];
        if (old_byte == new_byte)
            my_printf("\x1b[2;37m");
        if (my_ucharlen(new_byte, 16) < 2)
            my_printf("0");
        my_printf("%x", new_byte);
        if (old_byte == new_byte)
            my_printf("\x1b[0m", new_byte);
        if (i % 25 == 24) {
            my_printf("\n");
        } else {
            my_printf(" ");
        }
    }
}