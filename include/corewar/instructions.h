/*
** EPITECH PROJECT, 2021
** instructions
** File description:
** Source code
*/

#ifndef C9B9B24D_0042_4C39_85A6_CCDA2F2339E1
#define C9B9B24D_0042_4C39_85A6_CCDA2F2339E1

#include "corewar/corewar.h"

struct instruction_map {
    byte_t opcode;
    bool (*execute)(runtime_op_t *op, vm_t *vm,
        program_memory_t *instance);
};

bool aff(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool fork_op(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool live(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool zjmp(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool and(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool add(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool xor(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool or(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool sub(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool lfork(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool st(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

bool sti(runtime_op_t *op, vm_t *vm, program_memory_t *instance);

#endif /* C9B9B24D_0042_4C39_85A6_CCDA2F2339E1 */
