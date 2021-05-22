/*
** EPITECH PROJECT, 2021
** util
** File description:
** Source code
*/

#ifndef D7E5D541_192D_4F43_B332_01BACAEF35CE
#define D7E5D541_192D_4F43_B332_01BACAEF35CE

#include "corewar/corewar.h"
#include <asm/compiler.h>

int init_memory(program_memory_t *mem);
void destroy_memory(program_memory_t *mem);

program_memory_t *alloc_program_memory(void);
void free_program_memory(program_memory_t *mem);

void move_to_champion_pos(program_memory_t *mem, program_memory_t *champ);

runtime_op_t *alloc_runtime_op(void);
void free_runtime_op(runtime_op_t *op);

int append_instance(champion_t *champ, program_memory_t *instance);


size_t distance_between_instructions(instruction_t *ins_1,
                                    instruction_t *ins_2);
#endif /* D7E5D541_192D_4F43_B332_01BACAEF35CE */
