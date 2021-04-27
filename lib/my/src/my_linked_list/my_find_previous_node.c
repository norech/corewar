/*
** EPITECH PROJECT, 2020
** my_find_previous_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

void *my_find_previous_node(void **head_ptr, void *element_ptr)
{
    linked_list_t *head = *head_ptr;
    linked_list_t *element = element_ptr;
    linked_list_t *prev = NULL;

    FOREACH_NODE(head, current) {
        if (current == element)
            break;
        prev = current;
    }
    return (prev);
}