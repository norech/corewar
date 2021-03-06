/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Header for libmy
*/
#include <unistd.h>
#include <my/def.h>
#include <my/str.h>
#include <my/math.h>
#include <my/result.h>
#include <my/common.h>

#ifndef MY_H_
#define MY_H_

typedef struct bit_address {
    void *position;
    unsigned char offset;
} bit_address_t;

#define BIT_ADDR(byte, offset) \
    &((bit_address_t) { byte, offset })

#define BIT_ADDR_LSB(element, bitsize) \
    BIT_ADDR(element, 8 - bitsize)

#define MY_ASSERT(condition, return_code_on_fail, ...) \
    if (!(condition)) { \
        my_dprintf(2, "%s:%d: Assertion '%s' failed: %s\n", \
        __FILE__, __LINE__, #condition, ##__VA_ARGS__, ""); \
        return (return_code_on_fail); \
    }

#endif
