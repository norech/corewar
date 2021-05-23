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
#include <corewar/debug.h>

static const char *OWNER_COLOR[] = {
    "\x1b[48;2;40;40;100m\x1b[37m",
    "\x1b[48;2;150;20;20m\x1b[37m",
    "\x1b[48;2;20;100;20m\x1b[37m",
    "\x1b[48;2;20;20;100m\x1b[37m" };

static void print_debug_byte(runtime_op_t *curr_op, program_memory_t *mem,
    char *old, int index)
{
    byte_t old_byte = old[index];
    byte_t new_byte = mem->start_pos[index].data;
    int owner = mem->start_pos[index].owner;

    if (owner != 0)
        my_printf(OWNER_COLOR[owner % COUNTOF(OWNER_COLOR)]);
    if (old_byte == new_byte)
        my_printf("\x1b[2m");
    if (curr_op != NULL
        && mem->start_pos + index >= mem->pos - curr_op->bytecount
        && mem->start_pos + index < mem->pos)
        my_printf("\x1b[33m");
    if (mem->start_pos + index == mem->pos)
        my_printf("\x1b[1m\x1b[3m");
    if (my_ucharlen(new_byte, 16) < 2)
        my_printf("0");
    my_printf("%x\x1b[0m", new_byte);
}

void debug_memory(runtime_op_t *curr_op, program_memory_t *mem)
{
    size_t len = mem->end_pos - mem->start_pos;
    static char *old = NULL;

    if (old == NULL)
        old = my_calloc(len, sizeof(char));
    for (size_t i = 0; i < len; i++) {
        print_debug_byte(curr_op, mem, old, i);
        if (i % 32 == 31 || i == len - 1) {
            my_printf("\n");
        } else {
            my_printf(" ");
        }
    }
    my_memcpy(old, mem->start_pos, len);
}

void debug_and_pause(runtime_op_t *op, program_memory_t *mem)
{
    char buff;
    int pc;

    if (mem != NULL) {
        debug_memory(op, mem);
        for (int i = 1; i <= REG_NUMBER; i++) {
            my_printf("r%d = %d", i, mem->registers[i - 1]);
            my_printf("%s", (i == 16 || i % 4 == 0) ? "\n" : "\t\t");
        }
        pc = mem->pos - mem->start_pos;
        my_printf("carry = %d\tpc = %d\n", mem->carry, pc);
        my_printf("\n");
    }
    if (op != NULL) {
        print_op(op);
    }
    my_printf("\nPress ENTER for next step\n");
    read(0, &buff, 1);
}