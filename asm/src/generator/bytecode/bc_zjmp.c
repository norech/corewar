/*
** EPITECH PROJECT, 2021
** bc_sub
** File description:
** Source code
*/

#include <unistd.h>
#include <corewar/corewar.h>
#include <corewar/op.h>
#include <my/str.h>
#include <asm/util.h>

int bc_zjmp(int fd, dir_t val)
{
    int size = 0;
    byte_t code = OP_ZJMP;

    size += write(fd, &code, 1);
    size += write_endian(fd, &val, sizeof(val));
    return (size);
}