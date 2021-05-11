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

Test(fetch_str, basic)
{
    char input[] = { 0x05, 0x00, 0x00, 0x00, 'H', 'e', 'l', 'l', 'o' };
    char *output;

    program_memory_t *mem = t_create_program_memory(250);

    cr_assert_neq(mem, NULL);
    t_set_bytes_data(mem, &input, sizeof(input));
    mem->pos = mem->start_pos;

    cr_assert_eq(fetch_str(&output, mem), 5);
    cr_assert_str_eq(output, "Hello");
    cr_assert_eq(mem->pos, mem->start_pos + sizeof(int) + 5);
}