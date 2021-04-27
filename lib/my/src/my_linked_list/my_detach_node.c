/*
** EPITECH PROJECT, 2020
** my_remove_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>
#include <stdlib.h>

void my_detach_node(void **head, void *element_ptr)
{
    linked_list_t *element = element_ptr;
    linked_list_t *head_element = *head;

    if (*head == NULL)
        return;
    if (element == *head) {
        *head = element->next;
    } else {
        FOREACH_NODE(head_element, current) {
            if (current->next != element)
                continue;
            current->next = element->next;
            break;
        }
    }
    if (element != NULL)
        element->next = NULL;
}