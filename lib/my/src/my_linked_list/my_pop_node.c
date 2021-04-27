/*
** EPITECH PROJECT, 2020
** my_pop_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>
#include <stdlib.h>

void my_pop_node(void **head)
{
    linked_list_t *prev = NULL;
    linked_list_t *current = *head;

    if (current == NULL)
        return;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
        *head = NULL;
    else
        prev->next = NULL;
    free(current);
}