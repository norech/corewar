/*
** EPITECH PROJECT, 2020
** my_push_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

void my_push_node(void **head_ptr, void *element)
{
    linked_list_t *head = *head_ptr;
    linked_list_t *current = head;

    if (*head_ptr == NULL) {
        *head_ptr = element;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = element;
}