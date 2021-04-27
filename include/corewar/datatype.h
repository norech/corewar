/*
** EPITECH PROJECT, 2021
** datatype
** File description:
** Source code
*/

#ifndef CCAA70C1_76EE_4C10_A2D1_BD1B7137312A
#define CCAA70C1_76EE_4C10_A2D1_BD1B7137312A

#include <corewar/corewar.h>

///
/// fetch a char from the memory and move position to the next bytes.
/// fills the `chr_val` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_char(char *chr_val, program_memory_t *mem);

///
/// fetch an int from the memory and move position to the next bytes.
/// fills the `int_val` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_int(int *int_val, program_memory_t *mem);

///
/// fetch a string from the memory and move position to the next bytes.
/// fills the `str_val` argument with the value.
/// note: DOES allocate memory!
/// returns the length of the string.
/// returns -1 on error.
///
int fetch_str(char **str_val, program_memory_t *mem);

///
/// fetch an unsigned char from the memory and move position to the next bytes.
/// fills the `chr_val` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_uchar(unsigned char *chr_val, program_memory_t *mem);

#endif /* CCAA70C1_76EE_4C10_A2D1_BD1B7137312A */
