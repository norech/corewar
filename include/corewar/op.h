/*
** EPITECH PROJECT, 2021
** op
** File description:
** Source code
*/

#ifndef F0FDE37D_FFB1_46A6_8733_52016F7FF56D
#define F0FDE37D_FFB1_46A6_8733_52016F7FF56D

///
/// the operations and their opcodes
///
enum operations {
    OP_ADD = 0x01,
    OP_SUB = 0x02,
    OP_MUL = 0x03,
    OP_PUT = 0x04
};

#if COREWAR_VM
    #include <corewar/parser.h>
    ///
    /// the list of operations
    ///
    static const struct operation OP[] = {
        { 0x00 },
        { 0x01, "add", &parse_arithmetic_bc },
        { 0x02, "sub", &parse_arithmetic_bc },
        { 0x03, "mul", &parse_arithmetic_bc },
        { 0x04, "put", &parse_put_bc }
    };
#endif

#endif /* F0FDE37D_FFB1_46A6_8733_52016F7FF56D */
