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

int load_champion_from_bytes(champion_t *champ, byte_t *bytes, int bytes_count)
{
    write_relative_bytes(&champ->instances[0], bytes, bytes_count);
    return (0);
}