/*
** EPITECH PROJECT, 2021
** generator
** File description:
** Source code
*/

#ifndef BE8984EE_904D_48BB_AB8C_B9E60AAAD082
#define BE8984EE_904D_48BB_AB8C_B9E60AAAD082

#include "asm/parser.h"
#include "corewar/op.h"

typedef struct generator {
    int fd;
    header_t *header;
    instructions_ll_t instructions;
} generator_t;


int init_generator(int output_fd, generator_t *generator, header_t *header,
    instructions_ll_t *instructions);

int generate_code(generator_t *generator);

#endif /* BE8984EE_904D_48BB_AB8C_B9E60AAAD082 */
