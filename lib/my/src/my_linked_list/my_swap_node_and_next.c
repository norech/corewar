/*
** EPITECH PROJECT, 2020
** my_swap_node_and_next
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

void my_swap_node_and_next(void **head, void *a_ptr)
{
    linked_list_t *prev = my_find_previous_node(head, a_ptr);
    linked_list_t *a = a_ptr;
    linked_list_t *b = a->next;
    linked_list_t *next;

    if (b == NULL)
        return;
    next = b->next;
    b->next = a;
    a->next = next;
    if (prev == NULL)
        *head = b;
    else
        prev->next = b;
}