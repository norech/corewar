/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** Sorts an array of ints
*/
#include <my.h>

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    while (i < size) {
        if (i != 0 && array[i] > array[i - 1]) {
            int element = array[i];
            array[i] = array[i - 1];
            array[i - 1] = element;
        }
        i++;
    }
}
