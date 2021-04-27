/*
** EPITECH PROJECT, 2020
** my_remove_node
** File description:
** Source code
*/
#include <my/linked_list.h>
#include <my/def.h>
#include <stdlib.h>

void my_remove_node(void **head, void *element)
{
    my_detach_node(head, element);
    free(element);
}