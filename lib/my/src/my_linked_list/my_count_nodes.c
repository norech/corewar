/*
** EPITECH PROJECT, 2020
** my_count_nodes
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>
#include <my.h>

int my_count_nodes(void **head_ptr)
{
    int i = 0;
    linked_list_t *head = *head_ptr;

    FOREACH_NODE(head, current)
        i++;
    return (i);
}
