/*
** EPITECH PROJECT, 2021
** dump_memory
** File description:
** Source code
*/

#include <my/common.h>
#include <my/io.h>
#include <my.h>
#include <corewar/corewar.h>
#include <corewar/op.h>

static const char *OWNER_COLOR[] = {
    "\x1b[48;2;20;20;100m",
    "\x1b[48;2;150;20;20m",
    "\x1b[48;2;20;100;20m",
    "\x1b[48;2;20;20;100m" };

static void print_debug_byte(output_op_t *curr_op, program_memory_t *mem,
    char *old, int index)
{
    byte_t old_byte = old[index];
    byte_t new_byte = mem->start_pos[index].data;
    int owner = mem->start_pos[index].owner;

    if (old_byte == new_byte)
        my_printf("\x1b[2m");
    if (mem->start_pos + index == mem->pos)
        my_printf("\x1b[1m");
    if (curr_op != NULL
        && mem->start_pos + index >= mem->pos - curr_op->bytecount
        && mem->start_pos + index < mem->pos)
        my_printf("\x1b[33m");
    if (owner != 0)
        my_printf(OWNER_COLOR[owner % COUNTOF(OWNER_COLOR)]);
    if (my_ucharlen(new_byte, 16) < 2)
        my_printf("0");
    my_printf("%x\x1b[0m", new_byte);
}

void debug_memory(output_op_t *curr_op, program_memory_t *mem)
{
    size_t len = mem->end_pos - mem->start_pos;
    static char *old = NULL;

    if (old == NULL)
        old = my_calloc(len, sizeof(char));
    for (size_t i = 0; i < len; i++) {
        print_debug_byte(curr_op, mem, old, i);
        if (i % 25 == 24 || i == len - 1) {
            my_printf("\n");
        } else {
            my_printf(" ");
        }
    }
    my_memcpy(old, mem->start_pos, len);
}

static void print_arg(args_t *arg)
{
    switch (arg->type) {
        case ARG_CHAR:
            my_printf("%c", arg->chr_val);
            break;
        case ARG_BYTE:
            my_printf("0x");
            if (my_ucharlen(arg->byt_val, 16) < 2)
                my_printf("0");
            my_printf("%x", arg->chr_val);
            break;
        case ARG_INT:
            my_printf("%d", arg->int_val);
            break;
        case ARG_PTR:
            my_printf("%p", arg->ptr_val);
            break;
        case ARG_STR:
            my_printf("'%s'", arg->str_val);
            break;
    }
}

void debug_and_pause(output_op_t *op, program_memory_t *mem)
{
    char buff;

    if (mem != NULL) {
        debug_memory(op, mem);
    }
    if (op != NULL) {
        my_printf("%s [ ", OP[op->code].mnemo);
        for (int i = 0; i < op->args_count; i++) {
            print_arg(&op->args[i]);
            my_printf(" ");
        }
        my_printf("]\n");
    }
    my_printf("\nPress ENTER for next step\n");
    read(0, &buff, 1);
}