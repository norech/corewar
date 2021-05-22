/*
** EPITECH PROJECT, 2021
** print_op
** File description:
** Source code
*/

#include <my/common.h>
#include <my/io.h>
#include <my.h>
#include <corewar/corewar.h>
#include <corewar/op.h>

static void print_arg(arg_t *arg)
{
    switch (arg->type) {
        case ARG_REG_ID:
            if (IS_INVALID_REGISTER_ID(arg->reg_id))
                my_printf("\x1b[31m");
            my_printf("r%d", arg->reg_id);
            if (IS_INVALID_REGISTER_ID(arg->reg_id))
                my_printf("\x1b[0m");
            break;
        case ARG_DIR_NB:
            my_printf("%c%hd", '%', (short)arg->dir_val);
            break;
        case ARG_IND_NB:
            my_printf("%d", arg->ind_val);
            break;
    }
}

void print_op(runtime_op_t *op)
{
    if (IS_INVALID_OP(op->code)) {
        my_printf("Invalid op code: 0x");
        if (my_ucharlen(op->code, 16) < 2)
            my_printf("0");
        my_printf("%x\n", op->code);
        return;
    }
    my_printf("0x");
    if (my_ucharlen(op->code, 16) < 2)
        my_printf("0");
    my_printf("%x - ", op->code);
    my_printf("%s ", OP_TAB[op->code].mnemo);
    for (int i = 0; i < op->args_count; i++) {
        if (i != 0)
            my_printf(",");
        print_arg(&op->args[i]);
    }
    my_printf("\n");
}