/*
** EPITECH PROJECT, 2021
** write_number
** File description:
** Source code
*/

#include <my/io.h>
#include "corewar/corewar.h"
#include "asm/util.h"

int write_endian_offset(int fd, void *data, size_t src_size, size_t target_size)
{
    data = (char *)data + (target_size - src_size);
    my_printf("%d", *(char *)data);
    return (write_endian(fd, data, target_size));
}