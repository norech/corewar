/*
** EPITECH PROJECT, 2021
** bc_coding_byte
** File description:
** Source code
*/

#include "corewar/corewar.h"
#include <unistd.h>
#include <corewar/op.h>
#include <asm/util.h>
#include <my/str.h>

void bc_coding_byte(int fd, arg_type_t *args)
{
    byte_t coding_byte = 0;

    for (int i = 0; args[i] != 0; i++) {
        coding_byte = (coding_byte << 2) + args[i];
    }
    write(fd, &coding_byte, sizeof(coding_byte));
}