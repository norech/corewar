/*
** EPITECH PROJECT, 2021
** get_arg_value
** File description:
** Source code
*/

#include "corewar/op.h"
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <stdio.h>

reg_data_t resolve_arg_value(arg_t *arg, program_memory_t *mem,
    bool is_idx_mod_index)
{
    reg_data_t output = 0;
    int index;

    if (arg->type == ARG_DIR_NB)
        output = arg->dir_val;
    if (arg->type == ARG_IND_NB) {
        index = arg->ind_val;
        jump_relative_bytes(mem, is_idx_mod_index ? index % IDX_MOD : index);
        copy_relative_endian_bytes(&output, mem, sizeof(reg_data_t));
        jump_relative_bytes(mem, -(is_idx_mod_index ? index % IDX_MOD : index));
    }
    if (arg->type == ARG_REG_ID
        && arg->reg_id != 0 && arg->reg_id <= REG_NUMBER) {
        output = mem->registers[arg->reg_id - 1];
    }
    return (output);
}

short resolve_arg_index_value(arg_t *arg, program_memory_t *mem,
    bool is_idx_mod_index, bool is_idx_mod_val)
{
    reg_data_t data = resolve_arg_value(arg, mem, is_idx_mod_index);

    if (is_idx_mod_val)
        return ((short)data % IDX_MOD);
    return ((short)data);
}
