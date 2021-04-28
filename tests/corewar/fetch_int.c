/*
** EPITECH PROJECT, 2021
** fetch_int
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

Test(fetch_int, basic)
{
    int input = 10;
    int output;

    program_memory_t *mem = t_create_program_memory(250);

    t_set_bytes_data(mem, &input, sizeof(input));
    mem->pos = mem->start_pos;

    cr_assert_eq(fetch_int(&output, mem), 0);
    cr_assert_eq(output, input);
    cr_assert_eq(mem->pos, mem->start_pos + sizeof(int));
}