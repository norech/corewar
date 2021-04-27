/*
** EPITECH PROJECT, 2020
** my_reverse_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

void my_reverse_node(void **head)
{
    linked_list_t *current = *head;
    linked_list_t *prev = NULL;
    linked_list_t *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}