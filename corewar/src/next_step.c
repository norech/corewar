/*
** EPITECH PROJECT, 2021
** next_step
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>
#include <corewar/debug.h>
#include <corewar/parser.h>
#include <corewar/util.h>
#include <corewar/instructions.h>

static const struct instruction_map INSTRUCTIONS[] = {
    { OP_LIVE, live },
    { OP_ZJMP, zjmp },
    { OP_FORK, fork_op },
    { OP_AFF, aff },
    { 0, NULL }
};

static int execute_op(champion_t *champion, program_memory_t *instance)
{
    runtime_op_t op;

    if (!parse_bytecode(&op, instance)) {
        debug_and_pause(&op, instance);
        return (-1);
    }
    debug_and_pause(&op, instance);
    for (int i = 0; INSTRUCTIONS[i].opcode != 0; i++) {
        if (INSTRUCTIONS[i].opcode != op.code)
            continue;
        return (INSTRUCTIONS[i].execute(&op, champion, instance));
    }
    return (-1);
}

static int schedule_op(program_memory_t *instance)
{
    byte_t op = instance->pos->data;

    if (IS_INVALID_OP(op)) {
        instance->sleep_cycles = 1;
        return (-1);
    }
    instance->sleep_cycles = OP_TAB[op].cycles_count;
    return (0);
}

static int next_instance_step(program_memory_t *mem UNUSED,
    champion_t *champion, int instance_id)
{
    program_memory_t *instance = &champion->instances[instance_id];

    if (instance->sleep_cycles > 0) {
        instance->sleep_cycles--;
        return (0);
    }
    execute_op(champion, instance);
    instance = &champion->instances[instance_id];
    schedule_op(instance);
    return (0);
}

int next_step(program_memory_t *mem, champion_t *champions UNUSED)
{
    int instances_count;
    for (int i = 0; champions[i].instances != NULL; i++) {
        instances_count = champions[i].instances_count;
        for (int j = 0; j < instances_count; j++) {
            next_instance_step(mem, &champions[i], j);
        }
    }
    return (0);
}