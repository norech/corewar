/*
** EPITECH PROJECT, 2020
** my_insert_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>

void my_insert_node(void **head_ptr, int index, void *element_ptr)
{
    linked_list_t *head = *head_ptr;
    linked_list_t *element = element_ptr;
    int i = 0;

    FOREACH_NODE(head, current) {
        if (i == index) {
            element->next = current->next;
            current->next = element;
            break;
        }
        i++;
    }
}