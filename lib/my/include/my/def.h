/*
** EPITECH PROJECT, 2020
** defmy
** File description:
** Some useful definitions for mylib
*/

#include <stdlib.h>

#ifndef DEFMY_H_
#define DEFMY_H_

#define FOREACH(array, index) \
    for (size_t index = 0; (size_t)array[index] != 0; index++)

#define FOREACH_PAIR(array, index, value) \
    for (size_t index = 0; (size_t)(value = array[index]) != 0; index++)

#define FOREACH_NODE(head, current) \
    for (__typeof__(head) current = head; current != NULL; \
            current = current->next)

#define ITERATE(array) \
    for (; (size_t)(*array) != 0; array++)

#define GET_12TH_ARG(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, ...) a12

#define ARGS_COUNT(...) \
    GET_12TH_ARG(0, ## __VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define BITGET(byte, position) \
    ((byte & (1 << position)) >> position)

#define BITSET(byte, position, enabled) \
    (!enabled && BITGET(byte, position) == 1) \
        ? (byte = (byte ^ (1 << position))) \
        : ( \
            (enabled && BITGET(byte, position) == 0) \
                ? (byte = (byte | (1 << position))) \
                : (byte) \
        )

#define GET_ARG_OR_DEFAULT(dummy, arg, ...) arg

#define FREE(var) \
    (var != NULL ? free(var) : NULL, var = NULL)

#define UNUSED __attribute__((unused))
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define WHITE "\033[0;37m"
#define RESET WHITE

#endif
