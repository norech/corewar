/*
** EPITECH PROJECT, 2021
** live
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include <corewar/corewar.h>
#include <corewar/memory.h>
#include <corewar/op.h>

bool live(runtime_op_t *op UNUSED, champion_t *champ,
    program_memory_t *instance)
{
    my_printf("The player %d(%s)is alive.\n", instance->owner_id, champ->name);
    return (true);
}