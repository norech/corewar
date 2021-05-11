/*
** EPITECH PROJECT, 2021
** write_file_in_memory
** File description:
** Source code
*/

#include <my.h>
#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <fcntl.h>
#include <unistd.h>

bool write_file_in_memory(program_memory_t *mem, char *file)
{
    int fd = open(file, O_RDONLY);
    header_t header;
    char buff[1024];
    ssize_t len;

    if (fd < 0)
        return (false);
    if (!read(fd, &header, sizeof(header_t)))
        return (false);
    my_memcpy(mem->prog_name, header.prog_name, sizeof(mem->prog_name));
    while ((len = read(fd, buff, 1024)) != 0) {
        if (len == -1)
            return (false);
        write_relative_bytes(mem, buff, len);
    }
    return (true);
}