/*
** EPITECH PROJECT, 2020
** my_get_node_index
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

int my_get_node_index(void **head_ptr, void *element_ptr)
{
    int i = 0;
    linked_list_t *head = *head_ptr;

    FOREACH_NODE(head, current) {
        if (current == element_ptr)
            break;
        i++;
    }
    return (i);
}