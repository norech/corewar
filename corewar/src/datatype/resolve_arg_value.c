/*
** EPITECH PROJECT, 2021
** get_arg_value
** File description:
** Source code
*/

#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>

reg_data_t resolve_arg_value(arg_t *arg, program_memory_t *mem)
{
    reg_data_t output = 0;

    if (arg->type == ARG_DIR_NB)
        output = arg->dir_val;
    if (arg->type == ARG_IND_NB) {
        jump_relative_bytes(mem, arg->ind_val);
        copy_relative_endian_bytes(&output, mem, arg->ind_val);
        jump_relative_bytes(mem, -arg->ind_val);
    }
    if (arg->type == ARG_REG_ID
        && arg->reg_id != 0 && arg->reg_id <= REG_NUMBER) {
        output = mem->registries[arg->reg_id - 1];
    }
    return (output);
}