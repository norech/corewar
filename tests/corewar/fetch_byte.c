/*
** EPITECH PROJECT, 2021
** fetch_char
** File description:
** Source code
*/

#include <corewar/corewar.h>
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <corewar/datatype.h>
#include <corewar/debug.h>
#include <my/io.h>
#include "./tests.h"

Test(fetch_byte, basic)
{
    byte_t input = 0x03;
    byte_t output;

    program_memory_t *mem = t_create_program_memory(250);

    t_set_bytes_data(mem, &input, sizeof(input));
    mem->pos = mem->start_pos;

    cr_assert_eq(fetch_byte(&output, mem), 0);
    cr_assert_eq(output, input);
    cr_assert_eq(mem->pos, mem->start_pos + sizeof(byte_t));
}