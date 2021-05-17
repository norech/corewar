/*
** EPITECH PROJECT, 2021
** analyzer_error
** File description:
** Source code
*/

#include <my/str.h>
#include "corewar/corewar.h"
#include "corewar/op.h"
#include <asm/parser.h>

int analyzer_error(analyzer_t *analyzer, instruction_t *instruction,
    enum analyzer_error_code code, char *message)
{
    unsigned long i = 0;

    while (analyzer->errors[i].code != NO_ANALYZER_ERROR && i <
        COUNTOF(analyzer->errors))
        i++;
    if (i < COUNTOF(analyzer->errors)) {
        analyzer->errors[i].is_instr = true;
        analyzer->errors[i].instr = instruction;
        analyzer->errors[i].code = code;
        analyzer->errors[i].message = message;
    }
    return (-code);
}