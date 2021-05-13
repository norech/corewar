/*
** EPITECH PROJECT, 2021
** memory
** File description:
** Source code
*/

#ifndef D2BF0B2A_7B9B_4B0B_99BD_994AB378702F
#define D2BF0B2A_7B9B_4B0B_99BD_994AB378702F

#include <corewar/corewar.h>

///
/// copy `count` bytes from the memory (starting from current position).
/// DO NOT USE IT FOR NUMBERS. USE `copy_relative_endian_bytes` INSTEAD.
///
void copy_relative_bytes(void *dest, program_memory_t *mem, size_t count);

///
/// copy `count` bytes from the memory (starting from current position).
/// exactly the same as `copy_relative_bytes`, but the copied bytes are swapped
/// if the host is not big endian, to keep the correct endianness for numbers.
///
void copy_relative_endian_bytes(void *dest, program_memory_t *mem,
    size_t count);

///
/// move to another relative position. adds `increment` to the current position.
///
void jump_relative_bytes(program_memory_t *mem, size_t increment);

///
/// write `count` bytes from src to the memory (starting from current position).
/// then moves the cursor after the end of written (old_pos + count)
///
void write_relative_bytes(program_memory_t *mem, void *src, size_t count);

#endif /* D2BF0B2A_7B9B_4B0B_99BD_994AB378702F */
