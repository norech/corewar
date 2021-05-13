/*
** EPITECH PROJECT, 2021
** compiler
** File description:
** Source code
*/

#include "asm/bytecode.h"
#include "asm/parser.h"
#include <asm/compiler.h>
#include <unistd.h>

int compile_string(int output_fd, char *input_filename, char *input)
{
    parser_t parser;

    init_parser(&parser, input_filename, input);
    if (parse_program(&parser) < 0) {
        show_errors(&parser);
        return (-1);
    }
    write(output_fd, "hello\n", 6);
    return (0);
}