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
    { OP_AND, and},
    { OP_ADD, add},
    { OP_XOR, xor},
    { OP_OR, or},
    { OP_SUB, sub},
    { OP_LFORK, lfork },
    { OP_ST, st },
    { OP_STI, sti },
    { OP_LD, ld },
    { 0, NULL }
};

static int execute_op(vm_t *vm, program_memory_t *instance)
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
        return (INSTRUCTIONS[i].execute(&op, vm, instance));
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

static int next_instance_step(vm_t *vm, int champion_id, int instance_id)
{
    champion_t *champion = &vm->champions[champion_id];
    program_memory_t *instance = &champion->instances[instance_id];

    if (instance->sleep_cycles > 0) {
        instance->sleep_cycles--;
        return (0);
    }
    execute_op(vm, instance);
    instance = &champion->instances[instance_id];
    schedule_op(instance);
    return (0);
}

int check_winner(vm_t *vm)
{
    int alive_players = 0;
    champion_t *champion;

    for (int i = 0; vm->champions[i].instances != NULL; i++) {
        if (vm->champions[i].is_dead)
            continue;
        champion = &vm->champions[i];
        alive_players += 1;
    }
    if (alive_players == 1) {
        my_printf("The player %d(%s)has won.\n", champion->prog_number,
            champion->name);
    } else if (alive_players == 0) {
        my_printf("No winner :(\n");
    }
    return (alive_players <= 1 ? 1 : 0);
}

int next_step(vm_t *vm)
{
    int instances_count;

    for (int i = 0; vm->champions[i].instances != NULL; i++) {
        if (vm->champions[i].cycles_since_last_live >= vm->cycles_to_die)
            vm->champions[i].is_dead = true;
        if (vm->champions[i].is_dead)
            continue;
        vm->champions[i].cycles_since_last_live++;
        instances_count = vm->champions[i].instances_count;
        for (int j = 0; j < instances_count; j++) {
            next_instance_step(vm, i, j);
        }
    }
    return (check_winner(vm));
}