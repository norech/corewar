/*
** EPITECH PROJECT, 2020
** mylinkedlist
** File description:
** Source code
*/

#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

typedef struct linked_list {
    struct linked_list *next;
} linked_list_t;

#define HEAD(node) \
    ((void **)&node)

int      my_count_nodes(void **head);

void    *my_find_previous_node(void **head, void *element);

void    *my_get_last_node(void **head);

int      my_get_node_index(void **head, void *element);

void     my_insert_node(void **head, int index, void *element);

void     my_pop_node(void **head);

void     my_push_node(void **head, void *element);

void     my_detach_node(void **head, void *element_ptr);

void     my_remove_node(void **head, void *element);

void     my_reverse_node(void **head);

void     my_shift_node(void **head);

void     my_swap_node_and_next(void **head, void *a);

void     my_unshift_node(void **head, void *element);


static inline void my_prepend_node(void **head, void *element)
{
    my_unshift_node(head, element);
}

static inline void my_append_node(void **head, void *element)
{
    my_push_node(head, element);
}

#endif //MY_LINKED_LIST_H