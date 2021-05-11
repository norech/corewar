/*
** EPITECH PROJECT, 2021
** write_reversed
** File description:
** Source code
*/

#include "corewar/corewar.h"
#include <unistd.h>

int write_reversed(int fd, void *data, size_t size)
{
    int total_written = 0;
    int code = 0;
    byte_t *bytes = (byte_t *)data;

    for (size_t i = 0; i < size; i++) {
        code = write(fd, &bytes[size - i - 1], 1);
        if (code == -1)
            return (-1);
        total_written += code;
    }
    return (total_written);
}