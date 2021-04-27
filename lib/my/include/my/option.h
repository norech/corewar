/*
** EPITECH PROJECT, 2021
** result
** File description:
** Source code
*/

#ifndef MY_OPTION_H
#define MY_OPTION_H
#include <my/types.h>

#define OPT(typename) \
    struct option__ ## typename

#define INIT_OPT(typename, T) \
    OPT(typename) { \
        bool is_some; \
        bool is_none; \
        T value; \
    }

#define SOME(typename, val) \
    ((OPT(typename)){ 1, 0, .value=val })

#define NONE(typename, ...) \
    ((OPT(typename)){ 0, 1 })

#define OPT_UNWRAP_OR(res, default) (!(res).empty ? (res).value : (default))

INIT_OPT(char, char);
INIT_OPT(int, int);
INIT_OPT(str_t, str_t);
INIT_OPT(mut_str_t, mut_str_t);

#endif //MY_OPTION_H