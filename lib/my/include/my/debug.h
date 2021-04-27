/*
** EPITECH PROJECT, 2021
** debug
** File description:
** Source code
*/

#ifndef MY_DEBUG_H
#define MY_DEBUG_H
#include <my/def.h>

void   my_array_print_floatarr(float *arr, ssize_t size);

void   my_array_print_strarr(char **arr, ssize_t size);

void   my_array_print_nbarr(size_t element_size, char* format, void *arr,
        ssize_t size);

void   my_array_print_u_nbarr(unsigned long long *arr, ssize_t size);

int    my_dprintf(fd_t, char *s, ...);


#define DEBUG_PRINTF(format, ...) \
    my_dprintf(2, "\e[32m%s:%d :\e[36m " format "\e[0m\n", \
        __FILE__, __LINE__, ## __VA_ARGS__)

#define Z__DEBUG__PRINT_ARRAY_SIZED(x, size) \
    _Generic((x), \
        char **: my_array_print_strarr((void *)(x), size), \
        char const **: my_array_print_strarr((void *)(x), size), \
        char *: my_array_print_nbarr(sizeof(char), "%hhd", (x), size), \
        short *: my_array_print_nbarr(sizeof(short), "%hd", (x), size),\
        int *: my_array_print_nbarr(sizeof(int), "%d", (x), size), \
        long *: my_array_print_nbarr(sizeof(long), "%ld", (x), size), \
        long long *: my_array_print_nbarr(sizeof(long long), "%lld", \
            (x), size), \
        unsigned char *: my_array_print_nbarr(sizeof(char), "%hhu", (x), size),\
        unsigned short *: my_array_print_nbarr(sizeof(short), "%hu", (x), \
            size), \
        unsigned int *: my_array_print_nbarr(sizeof(int), "%u", (x), size), \
        unsigned long *: my_array_print_nbarr(sizeof(long), "%lu", (x), size), \
        unsigned long long *: my_array_print_nbarr(sizeof(short), "%llu", (x), \
            size), \
        float *: my_array_print_floatarr((void *)(x), size), \
        double *: my_array_print_floatarr((void *)(x), size), \
        default: my_printf("unsupported") \
    )

#define DEBUG_PRINT_ARRAY(x, ...) \
    Z__DEBUG__PRINT_ARRAY_SIZED(x, GET_ARG_OR_DEFAULT(0, ## __VA_ARGS__, -1))

#endif //MY_DEBUG_H