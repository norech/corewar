/*
** EPITECH PROJECT, 2021
** generate_code
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

int generate_argument(generator_t *generator, instruction_t *instr, int arg_id)
{
    op_t *op_tab = &OP_TAB[instr->bytecode];
    dir_t dir = instr->args[arg_id].dir_val;
    ind_t ind = instr->args[arg_id].ind_val;

    if (instr->args[arg_id].type == ARG_DIR_NB)
        write_endian_offset(generator->fd, &dir, DIR_SIZE,
            (op_tab->type[arg_id] & T_IDX) == 0 ? DIR_SIZE : IND_SIZE);
    if (instr->args[arg_id].type == ARG_IND_NB)
        write_endian(generator->fd, &ind, IND_SIZE);
    if (instr->args[arg_id].type == ARG_REG_ID)
        write(generator->fd, &instr->args[arg_id].reg_id, 1);
    return (0);
}

int generate_coding_byte(generator_t *generator, instruction_t *instruction)
{
    byte_t byte = 0;
    int i = 0;

    if (!HAS_CODING_BYTE(instruction->bytecode))
        return (0);
    for (; i < instruction->args_count; i++)
        byte = (byte << 2) | (instruction->args[i].type);
    for (; i < 4; i++) {
        byte = (byte << 2);
    }
    write(generator->fd, &byte, 1);
    return (0);
}

int generate_instruction(generator_t *generator, instruction_t *instruction)
{
    write(generator->fd, &instruction->bytecode, 1);
    generate_coding_byte(generator, instruction);
    for (int i = 0; i < instruction->args_count; i++) {
        generate_argument(generator, instruction, i);
    }
    return (0);
}

int generate_instructions(generator_t *generator)
{
    instructions_ll_t *instr = &generator->instructions;

    for (instruction_t *node = instr->head; node != NULL; node = node->next) {
        generate_instruction(generator, node);
    }
    return (0);
}

int generate_code(generator_t *generator)
{
    swap_header(generator->header);
    write(generator->fd, generator->header, sizeof(header_t));
    generate_instructions(generator);
    return (0);
}