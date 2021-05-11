/*
** EPITECH PROJECT, 2021
** consume_instruction_keyword
** File description:
** Source code
*/

#include <my.h>
#include "corewar/op.h"
#include <asm/parser.h>
#include <asm/util.h>

byte_t consume_instruction_mnemo(parser_t *parser)
{
    int mnemo_len = 0;
    int max_mnemo_len = 0;
    byte_t op_code = 0;

    for (int i = OP_START; i < OP_END; i++) {
        mnemo_len = my_strlen(OP_TAB[i].mnemo);
        if (my_strncmp(parser->pos, OP_TAB[i].mnemo, mnemo_len) == 0
                && mnemo_len > max_mnemo_len) {
            max_mnemo_len = mnemo_len;
            op_code = OP_TAB[i].code;
        }
    }
    if (op_code != 0)
        parser->pos += max_mnemo_len;
    return (op_code);
}