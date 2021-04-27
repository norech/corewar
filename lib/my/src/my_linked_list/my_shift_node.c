/*
** EPITECH PROJECT, 2020
** my_shift_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <stdlib.h>

void my_shift_node(void **head)
{
    linked_list_t *current = *head;

    *head = current->next;
    free(current);
}