/*
** EPITECH PROJECT, 2021
** parser_labels
** File description:
** Source code
*/
#include <my.h>
#include <my/io.h>
#include "corewar/corewar.h"
#include "corewar/op.h"
#include <asm/parser.h>
#include <asm/util.h>

static int append(label_t **output_labels, label_t **prev, char *label_name,
    parser_t *parser)
{
    label_t *cur = NULL;

    cur = my_calloc(1, sizeof(label_t));
    if (cur == NULL)
        return (parser_error(parser, ALLOC_FAILED, NULL));
    cur->label = label_name;
    cur->prev = *prev;
    if (*prev != NULL)
        (*prev)->next = cur;
    if (*output_labels == NULL)
        *output_labels = cur;
    *prev = cur;
    return (0);
}

int parse_labels(label_t **output_labels, parser_t *parser)
{
    char *label = NULL;
    label_t *prev = NULL;
    int count = 0;
    int code;

    *output_labels = NULL;
    while ((code = consume_label(&label, parser)) > 0) {
        while (consume_whitespaces(parser) != 0
            || consume_newlines(parser) != 0);
        if (append(output_labels, &prev, label, parser) < 0)
            return (-1);
        count++;
    }
    return (code >= 0 ? count : code);
}
