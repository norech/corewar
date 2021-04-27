/*
** EPITECH PROJECT, 2021
** types
** File description:
** Source code
*/

#ifndef MY_TYPES_H
#define MY_TYPES_H

#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdbool.h>

typedef int8_t i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;
typedef int64_t i64_t;
typedef ptrdiff_t i128_t;
typedef ssize_t isize_t;

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;
typedef size_t usize_t;

typedef float f32_t;
typedef double f64_t;

#ifndef SOFT_TYPES
typedef char const * strpos_t;
typedef char const * str_t;
#else //SOFT_TYPES
typedef char * strpos_t;
typedef char * str_t;
#endif //SOFT_TYPES

typedef char * mut_str_t;

typedef void * any_t;

typedef int fd_t;

#endif //MY_TYPES_H