/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Swaps
*/
#include <my.h>

void my_swap(int *a, int *b)
{
    int addr;

    addr = *a;
    *a = *b;
    *b = addr;
}
