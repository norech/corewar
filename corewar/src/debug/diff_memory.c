/*
** EPITECH PROJECT, 2021
** dump_memory
** File description:
** Source code
*/

#include <my/common.h>
#include <my/io.h>
#include <corewar/corewar.h>

void diff_memory(char *old, char *new, size_t len)
{
    unsigned char old_byte;
    unsigned char new_byte;

    for (size_t i = 0; i < len; i++) {
        old_byte = old[i];
        new_byte = new[i];
        if (old_byte != new_byte)
            my_printf("%0x", new_byte);
        else
            my_printf("\x1b[2;37m%0x\x1b[2;0m", new_byte);
        if (i % 25 == 24) {
            my_printf("\n");
        } else {
            my_printf(" ");
        }
    }
}