/*
** EPITECH PROJECT, 2021
** result
** File description:
** Source code
*/

#ifndef MY_RESULT_H
#define MY_RESULT_H
#include <my/types.h>

#define RES(typename) \
    struct result__ ## typename

#define INIT_RES(typename, T) \
    RES(typename) { \
        bool is_ok; \
        bool is_err; \
        union { \
            int err; \
            T value; \
        }; \
    }

#define OK(typename, val) \
    ((RES(typename)){ 1, 0, .value=val })

#define ERR(typename, ...) \
    ((RES(typename)){ 0, 1, .err=(0, ## __VA_ARGS__) })

#define RES_UNWRAP_OR(res, default) ((res).is_ok ? (res).value : (default))
#define RES_UNWRAP(res) ((res).is_ok ? (res).value : (res).err)

INIT_RES(void, char);
INIT_RES(char, char);
INIT_RES(int, int);
INIT_RES(str_t, str_t);
INIT_RES(mut_str_t, mut_str_t);

#endif //MY_RESULT_H