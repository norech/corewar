/*
** EPITECH PROJECT, 2021
** copy_relative_bytes
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

Test(write_relative_bytes, outside_memory_bounds_2)
{
    byte_t input[4] = { 0x01, 0x05, 0x00, 0x00 };

    program_memory_t *mem = t_create_program_memory(4);

    mem->pos = mem->start_pos;

    write_relative_bytes(mem, input, 4);
    cr_assert_eq(mem->pos, mem->start_pos + 4);
    cr_assert_eq(mem->start_pos[0].data, input[0]);
    cr_assert_eq(mem->start_pos[1].data, input[1]);
    cr_assert_eq(mem->start_pos[2].data, input[2]);
    cr_assert_eq(mem->start_pos[3].data, input[3]);
}