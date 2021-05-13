/*
** EPITECH PROJECT, 2021
** next_step
** File description:
** Source code
*/

#include <my.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>
#include <corewar/debug.h>
#include <corewar/parser.h>
#include <corewar/util.h>

int next_step(program_memory_t *mem, champion_t *champions UNUSED)
{
    runtime_op_t op;

    parse_bytecode(&op, mem);
    debug_and_pause(&op, mem);
    return (0);
}