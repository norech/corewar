/*
** EPITECH PROJECT, 2020
** my_swap_ptr
** File description:
** Swaps pointers
*/

void my_swap_ptr(void **e1, void **e2)
{
    void *tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}