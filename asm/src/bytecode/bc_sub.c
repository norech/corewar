/*
** EPITECH PROJECT, 2021
** bc_sub
** File description:
** Source code
*/

#include <unistd.h>
#include <corewar/op.h>
#include <my/str.h>

void bc_sub(int fd, int val1, int val2)
{
    byte_t code = OP_SUB;

    write(fd, &code, 1);
    write(fd, &val1, sizeof(val1));
    write(fd, &val2, sizeof(val2));
}