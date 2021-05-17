/*
** EPITECH PROJECT, 2021
** compiler
** File description:
** Source code
*/

#include "asm/bytecode.h"
#include "asm/parser.h"
#include "asm/analyzer.h"
#include <asm/compiler.h>
#include <unistd.h>

int compile_string(int output_fd, char *input_filename, char *input)
{
    parser_t parser;
    analyzer_t analyzer;

    init_parser(&parser, input_filename, input);
    if (parse_program(&parser) < 0) {
        show_parser_errors(&parser);
        return (-1);
    }
    init_analyzer(&analyzer, &parser);
    write(output_fd, "hello\n", 6);
    if (analyze_program(&analyzer) < 0) {
        show_analyzer_errors(&analyzer);
        return (-1);
    }
    return (0);
}