/*
** EPITECH PROJECT, 2020
** my_array
** File description:
** Source code
*/
#include <unistd.h>
#include <my/types.h>

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

struct qsort_params {
    size_t size;
    void *matches;
    bool (*cmp)(struct qsort_params *params, void *a, void *b);
    void *additional_data;
};

#define ARRAY_FIND_ONE_IN(arr, cmp, value) \
    my_array_find_one(sizeof(arr[0]), arr, &cmp, (void *)(value))

#define ARRAY_FIND_ALL_IN(arr, cmp, value) \
    my_array_find_all(sizeof(arr[0]), arr, &cmp, (void *)(value))

#define ARRAY_EACH(arr, iter) \
    my_array_each(sizeof(arr[0]), arr, iter)

#define ARRAY_MAP(arr, iter) \
    my_array_map(sizeof(arr[0]), arr, iter)

#define ARRAY_COUNT(arr) \
    my_array_count(sizeof(arr[0]), arr)

#define ARRAY_MERGE(arr1, ...) \
    my_array_merge(sizeof(arr1[0]), \
        (__typeof__(arr1)[]) { arr1, ## __VA_ARGS__, NULL })

#define ARRAY_SLICE(arr, start, end) \
    my_array_slice(sizeof(arr[0]), arr, start, end)

int my_array_count(size_t element_size, void *array);

void *my_array_merge(size_t element_size, void **elements);

void *my_arraydup(size_t element_size, void *array);

void my_array_each(size_t element_size, void *array,
    void (*iter)(void *val));

void *my_array_map(size_t element_size, void *array,
    void *(*iter)(int i, void *val));

void *my_array_slice(size_t element_size, void *array, size_t start,
    size_t end);

void *my_array_find_one(size_t element_size, void *array,
    bool (*cmp)(size_t element_size, void *element, void *param), void *param);

void **my_array_find_all(size_t element_size, void *array,
    bool (*cmp)(size_t element_size, void *element, void *param), void *param);

void my_array_swap(size_t size, void *array, int i, int j);

void my_array_qsort(struct qsort_params *params, int low, int high);

bool with_value(size_t element_size, void *element, void *ref);

#endif //MY_ARRAY_H