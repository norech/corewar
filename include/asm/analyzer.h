/*
** EPITECH PROJECT, 2021
** analyzer
** File description:
** Source code
*/

#ifndef D3EA167C_BF89_49A7_8D21_4C27D453CC95
#define D3EA167C_BF89_49A7_8D21_4C27D453CC95

#include "asm/parser.h"


int analyze_program(analyzer_t *parser);

int analyze_signature(analyzer_t *analyzer, instruction_t *instruction);

int analyze_size(analyzer_t *analyzer, instruction_t *instruction);

int analyze_arg_labels(analyzer_t *analyzer, instruction_t *instruction);

#endif /* D3EA167C_BF89_49A7_8D21_4C27D453CC95 */
