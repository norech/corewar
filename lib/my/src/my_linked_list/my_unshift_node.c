/*
** EPITECH PROJECT, 2020
** my_unshift_node
** File description:
** Source code
*/
#include <my/linked_list.h>

void my_unshift_node(void **head, void *element_ptr)
{
    linked_list_t *element = element_ptr;
    element->next = *head;
    *head = element;
}