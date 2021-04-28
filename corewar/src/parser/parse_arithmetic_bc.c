/*
** EPITECH PROJECT, 2021
** parse_arithmetic
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/datatype.h>

bool parse_arithmetic_bc(output_op_t *op, program_memory_t *mem)
{
    op->args_count = 2;
    if (fetch_byte(&op->code, mem) < 0)
        return (false);
    op->args[0].type = ARG_INT;
    if (fetch_int(&op->args[0].int_val, mem) < 0)
        return (false);
    op->args[1].type = ARG_INT;
    if (fetch_int(&op->args[1].int_val, mem) < 0)
        return (false);
    op->bytecount = sizeof(byte_t) + 2 * sizeof(int);
    return (true);
}