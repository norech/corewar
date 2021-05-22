/*
** EPITECH PROJECT, 2021
** util
** File description:
** Source code
*/

#ifndef C4E5875A_EBCA_4383_B042_BC56B75C356B
#define C4E5875A_EBCA_4383_B042_BC56B75C356B

#include "asm/parser.h"
#include <stddef.h>
#include <unistd.h>

int pop_instruction(instructions_ll_t *list, instruction_t *instr);

int push_instruction(instructions_ll_t *list, instruction_t *instr);

int write_reversed(int fd, void *data, size_t size);

int write_endian(int fd, void *data, size_t size);

int write_endian_offset(int fd, void *data, size_t src_size,
    size_t target_size);

int get_line_num_parser(int *output_char_pos, parser_t *parser, char *curr_ptr);

int get_line_num_analyzer(int *output_char_pos, analyzer_t *analyzer,
    analyzer_error_t *error);

ssize_t distance_between_instructions(instruction_t *ins_1,
                                    instruction_t *ins_2);

int swap_header(header_t *header);

#endif /* C4E5875A_EBCA_4383_B042_BC56B75C356B */
