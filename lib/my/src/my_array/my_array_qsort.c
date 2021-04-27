/*
** EPITECH PROJECT, 2021
** my_array_qsort
** File description:
** Source code
*/

#include <my.h>
#include <my/array.h>

static int partition(struct qsort_params *params, int low, int high)
{
    size_t size = params->size;
    void *pivot = params->matches + high * size;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (!params->cmp(params, params->matches + j * size, pivot)) {
            i++;
            my_array_swap(size, params->matches, i, j);
        }
    }
    my_array_swap(size, params->matches, i + 1, high);
    return (i + 1);
}

void my_array_qsort(struct qsort_params *params, int low, int high)
{
    int pivot;

    if (low < high) {
        pivot = partition(params, low, high);
        my_array_qsort(params, low, pivot - 1);
        my_array_qsort(params, pivot + 1, high);
    }
}