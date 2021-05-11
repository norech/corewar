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
/// fetch an indirect value from the memory and move position to the next bytes.
/// fills the `ind_val` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_ind(ind_t *ind_val, program_memory_t *mem);

///
/// fetch a direct value from the memory and move position to the next bytes.
/// fills the `dir_val` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_dir(dir_t *dir_val, program_memory_t *mem);

///
/// fetch a registry id from the memory and move position to the next bytes.
/// fills the `reg_id` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_reg_id(reg_id_t *reg_id, program_memory_t *mem);

///
/// fetch a byte from the memory and move position to the next bytes.
/// fills the `chr_val` argument with the value.
/// returns 0 on success.
/// returns -1 on error.
///
int fetch_byte(byte_t *chr_val, program_memory_t *mem);

///
/// Resolve the value of the argument.
/// Will resolve indirect values.
/// Will go in registry.
///
reg_data_t resolve_arg_value(arg_t *arg, program_memory_t *mem);

#endif /* CCAA70C1_76EE_4C10_A2D1_BD1B7137312A */
