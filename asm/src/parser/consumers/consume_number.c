/*
** EPITECH PROJECT, 2021
** consume_number
** File description:
** Source code
*/

#include "asm/parser.h"
#include "my.h"
#include "my/result.h"

int consume_number(int *output_value, parser_t *parser)
{
    int len;
    RES(int) res = my_getnbr(parser->pos);

    if (res.is_err)
        return (0);
    *output_value = res.value;
    len = my_intlen(res.value, 10);
    parser->pos += len;
    return (len);
}