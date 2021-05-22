/*
** EPITECH PROJECT, 2021
** swap_header
** File description:
** Source code
*/

#include "corewar/corewar.h"
#include "corewar/op.h"

int swap_header(header_t *header)
{
    byte_t *magic_bytes = (byte_t *)&header->magic;
    byte_t *prog_size_bytes = (byte_t *)&header->prog_size;

    header->magic = (magic_bytes[0] << 24) | (magic_bytes[1] << 16)
        | (magic_bytes[2] << 8) | magic_bytes[3];
    header->prog_size = (prog_size_bytes[0] << 24) | (prog_size_bytes[1] << 16)
        | (prog_size_bytes[2] << 8) | prog_size_bytes[3];
    return (0);
}