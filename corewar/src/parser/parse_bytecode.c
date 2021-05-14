/*
** EPITECH PROJECT, 2021
** parse_op
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include "corewar/corewar.h"
#include "corewar/op.h"
#include "corewar/datatype.h"

static bool parse_arguments(runtime_op_t *op, program_memory_t *mem,
    op_t *tab_op)
{
    arg_t *arg;
    bool is_index = false;

    for (int i = 0; i < op->args_count; i++) {
        arg = &op->args[i];
        is_index = (tab_op->type[i] & T_IDX) != 0;
        if (arg->type == ARG_DIR_NB && fetch_dir(&arg->dir_val, mem,
                is_index) < 0)
            return (false);
        if (arg->type == ARG_IND_NB && fetch_ind(&arg->ind_val, mem) < 0)
            return (false);
        if (arg->type == ARG_REG_ID && fetch_reg_id(&arg->reg_id, mem) < 0)
            return (false);
    }
    return (true);
}

static bool parse_coding_byte(runtime_op_t *op, program_memory_t *mem)
{
    byte_t coding_byte;

    if (fetch_byte(&coding_byte, mem) < 0)
        return (false);
    for (int i = 0; i < op->args_count; i++) {
        switch (GET_CODING_OF_ARG(coding_byte, i)) {
            case 0b10:
                op->args[i].type = ARG_DIR_NB;
                break;
            case 0b11:
                op->args[i].type = ARG_IND_NB;
                break;
            case 0b01:
                op->args[i].type = ARG_REG_ID;
                break;
        }
    }
    return (true);
}

bool parse_bytecode(runtime_op_t *op, program_memory_t *mem)
{
    op_t *tab_op;
    memory_slot_t *parse_start_pos = mem->pos;

    my_memset(op, 0, sizeof(runtime_op_t));
    if (fetch_byte(&op->code, mem) < 0)
        return (false);
    if (IS_INVALID_OP(op->code))
        return (false);
    tab_op = &OP_TAB[op->code];
    op->args[0].type = CONVERT_TO_ARG_TYPE(tab_op->type[0]);
    op->args_count = tab_op->args_count;
    if (HAS_CODING_BYTE(op->code) && !parse_coding_byte(op, mem))
        return (false);
    if (!parse_arguments(op, mem, tab_op))
        return (false);
    op->bytecount = mem->pos - parse_start_pos;
    return (true);
}