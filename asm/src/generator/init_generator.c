/*
** EPITECH PROJECT, 2021
** init_generator
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include "asm/parser.h"
#include "asm/generator.h"
#include "asm/util.h"
#include "corewar/corewar.h"
#include "corewar/op.h"
#include <unistd.h>

int init_generator(int output_fd, generator_t *generator, header_t *header,
    instructions_ll_t *instructions)
{
    generator->fd = output_fd;
    generator->header = header;
    my_memcpy(&generator->instructions, instructions, sizeof(*instructions));
    return (0);
}