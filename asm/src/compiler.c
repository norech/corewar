/*
** EPITECH PROJECT, 2021
** compiler
** File description:
** Source code
*/

#include "asm/bytecode.h"
#include "asm/parser.h"
#include "asm/analyzer.h"
#include "asm/generator.h"
#include "corewar/op.h"
#include "corewar/util.h"
#include <asm/compiler.h>
#include <unistd.h>
#include <stdio.h>

int get_program_size(analyzer_t *analyzer)
{
    int size = 0;
    instructions_ll_t *instr = &analyzer->program.instructions;

    for (instruction_t *node = instr->head; node != NULL; node = node->next) {
        size += node->byte_count;
    }
    return (size);
}

int compile_string(int output_fd, char *input_filename, char *input)
{
    header_t header;
    parser_t parser;
    analyzer_t analyzer;
    generator_t generator;

    init_parser(&parser, &header, input_filename, input);
    if (parse_program(&parser) < 0) {
        show_parser_errors(&parser);
        return (-1);
    }
    init_analyzer(&analyzer, &parser);
    if (analyze_program(&analyzer) < 0) {
        show_analyzer_errors(&analyzer);
        return (-1);
    }
    init_generator(output_fd, &generator, &header,
        &analyzer.program.instructions);
    if (generate_code(&generator) < 0)
        return (-1);
    return (0);
}