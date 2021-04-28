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

Test(copy_relative_bytes, integer)
{
    int input = 10;
    int output;

    program_memory_t *mem = t_create_program_memory(250);

    t_set_bytes_data(mem, &input, sizeof(int));
    mem->pos = mem->start_pos; // we better be sure

    copy_relative_bytes(&output, mem, sizeof(int));
    cr_assert_eq(output, 10);
}

Test(copy_relative_bytes, str)
{
    char input[] = "hello world";
    char output[12];

    program_memory_t *mem = t_create_program_memory(250);

    t_set_bytes_data(mem, &input, sizeof(input));
    mem->pos = mem->start_pos; // we better be sure

    copy_relative_bytes(output, mem, sizeof(input));
    cr_assert_str_eq(output, "hello world");
}

Test(copy_relative_bytes, outside_memory_bounds)
{
    byte_t input[4] = { 0x00, 0x00, 0x00, 0x05 };
    byte_t expected[4] = { 0x05, 0x00, 0x00, 0x00 };
    byte_t output[4];

    program_memory_t *mem = t_create_program_memory(4);

    t_set_bytes_data(mem, input, 4);
    mem->pos = mem->end_pos - 1; // shift the position

    copy_relative_bytes(output, mem, sizeof(input));

    cr_assert_arr_eq(output, expected, 4);
}

Test(copy_relative_bytes, outside_memory_bounds_2)
{
    byte_t input[4] = { 0x01, 0x05, 0x00, 0x00 };
    byte_t expected[4] = { 0x05, 0x00, 0x00, 0x01 };
    byte_t output[4];

    program_memory_t *mem = t_create_program_memory(4);

    t_set_bytes_data(mem, input, 4);
    mem->pos = mem->start_pos + 1; // shift the position

    copy_relative_bytes(output, mem, 4);
    cr_assert_arr_eq(output, expected, 4);
}