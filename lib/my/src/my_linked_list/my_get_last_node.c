/*
** EPITECH PROJECT, 2020
** my_get_last_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

void *my_get_last_node(void **head)
{
    linked_list_t *current = *head;

    if (current == NULL)
        return (NULL);
    while (current->next != NULL)
        current = current->next;
    return (current);
}