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

bool live(runtime_op_t *op UNUSED, program_memory_t *mem)
{
    my_printf("The player %d(%s)is alive.\n", mem->owner_id, mem->prog_name);
    return (true);
}