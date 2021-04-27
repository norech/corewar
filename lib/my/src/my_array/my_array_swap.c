/*
** EPITECH PROJECT, 2021
** my_array_swap
** File description:
** Source code
*/

#include <unistd.h>
#include <my.h>

void my_array_swap(size_t size, void *array, int i, int j)
{
    unsigned char memory[size];

    my_memcpy(memory, array + i * size, size);
    my_memcpy(array + i * size, array + j * size, size);
    my_memcpy(array + j * size, memory, size);
}