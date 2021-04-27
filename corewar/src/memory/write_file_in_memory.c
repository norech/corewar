/*
** EPITECH PROJECT, 2021
** write_file_in_memory
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <fcntl.h>
#include <unistd.h>

bool write_file_in_memory(program_memory_t *mem, char *file)
{
    int fd = open(file, O_RDONLY);
    char buff[1024];
    ssize_t len;

    if (fd < 0)
        return (false);
    while ((len = read(fd, buff, 1024)) != 0) {
        if (len == -1)
            return (false);
        write_relative_bytes(mem, buff, len);
    }
    return (true);
}