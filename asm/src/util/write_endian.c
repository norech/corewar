/*
** EPITECH PROJECT, 2021
** write_number
** File description:
** Source code
*/

#include "corewar/corewar.h"
#include "asm/util.h"

int write_endian(int fd, void *data, size_t size)
{
    if (is_host_big_endian())
        return write(fd, data, size);
    else
        return write_reversed(fd, data, size);
}