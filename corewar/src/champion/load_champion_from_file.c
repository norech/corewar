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
#include <corewar/util.h>
#include <fcntl.h>
#include <unistd.h>

int load_champion_from_file(champion_t *champ, char *file)
{
    int fd = open(file, O_RDONLY);
    header_t header;
    char buff[1024];
    ssize_t len;
    memory_slot_t *pos = champ->instances[0].pos;

    if (fd < 0)
        return (-1);
    if (!read(fd, &header, sizeof(header_t)))
        return (-1);
    swap_header(&header);
    my_memcpy(champ->name, header.prog_name, sizeof(champ->name));
    while ((len = read(fd, buff, 1024)) != 0) {
        if (len == -1)
            return (-1);
        write_relative_bytes(&champ->instances[0], buff, len);
    }
    champ->instances[0].pos = pos;
    close(fd);
    return (0);
}