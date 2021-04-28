/*
** EPITECH PROJECT, 2021
** jump_relative_bytes
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <corewar/memory.h>
#include <corewar/debug.h>
#include <my/io.h>
#include "./tests.h"

Test(jump_relative_bytes, zero)
{
    program_memory_t *mem = t_create_program_memory(10);

    mem->pos = mem->start_pos; // we better be sure

    jump_relative_bytes(mem, 0);
    cr_assert_eq(mem->pos, mem->start_pos);
}

Test(jump_relative_bytes, positive)
{
    program_memory_t *mem = t_create_program_memory(10);

    mem->pos = mem->start_pos; // we better be sure

    jump_relative_bytes(mem, 4);
    cr_assert_eq(mem->pos, mem->start_pos + 4);
}

Test(jump_relative_bytes, negative)
{
    program_memory_t *mem = t_create_program_memory(10);

    mem->pos = mem->start_pos; // we better be sure

    jump_relative_bytes(mem, -4);
    cr_assert_eq(mem->pos, mem->end_pos - 4);
}

Test(jump_relative_bytes, wayyy_too_far_positive)
{
    program_memory_t *mem = t_create_program_memory(10);

    mem->pos = mem->start_pos; // we better be sure

    jump_relative_bytes(mem, 24);
    cr_assert_eq(mem->pos, mem->start_pos + 4);
}

Test(jump_relative_bytes, wayyy_too_far_negative)
{
    program_memory_t *mem = t_create_program_memory(10);

    mem->pos = mem->start_pos; // we better be sure

    jump_relative_bytes(mem, -24);
    cr_assert_eq(mem->pos, mem->end_pos - 4);
}