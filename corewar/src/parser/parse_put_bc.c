/*
** EPITECH PROJECT, 2021
** parse_put_bc
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <corewar/datatype.h>

bool parse_put_bc(output_op_t *op, program_memory_t *mem)
{
    int len;

    op->args_count = 1;
    if (fetch_uchar(&op->code, mem) < 0)
        return (false);
    op->args[0].type = ARG_STR;
    if ((len = fetch_str(&op->args[0].str_val, mem)) < 0)
        return (false);
    op->bytecount = sizeof(char) + sizeof(int) + len;
    return (op);
}