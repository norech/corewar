/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** Source code
*/

#ifndef D2C3323B_231E_4734_9476_D89C4C20A637
#define D2C3323B_231E_4734_9476_D89C4C20A637

#include <stdlib.h>
#include <stdbool.h>

///
/// the type of argument
///
enum arg_type {
    ARG_CHAR,
    ARG_BYTE,
    ARG_INT,
    ARG_STR,
    ARG_PTR
};

///
/// Unsigned char, used for byte representation
///
typedef unsigned char byte_t;

///
/// an argument passed to a parsed operation
///
typedef struct arg {
    ///
    /// the type of the argument
    ///
    enum arg_type type;

    ///
    /// the value of the argument.
    /// this union let you access variables by doing
    /// arg.chr_val or arg->chr_val
    ///
    union {
        char chr_val;
        byte_t byt_val;
        int int_val;
        void *ptr_val;
        char *str_val;
    };
} args_t;

typedef struct {
    byte_t data;
    byte_t owner;
} memory_slot_t;

///
/// the interface between any memory access and the memory array
///
typedef struct program_memory {
    ///
    /// Owner id to use when memory is rewritten
    ///
    byte_t owner_id;

    ///
    /// start position of the accessible memory array.
    ///
    memory_slot_t *start_pos;

    ///
    /// end position of the accessible memory array.
    /// usually `start_pos + length`.
    ///
    memory_slot_t *end_pos;

    ///
    /// current position in memory.
    /// any operation in memory or execution is done at this address.
    /// can be used as a program counter (PC).
    /// since memory is circular, when doing memory operations
    /// (from memory.h functions), setting pos to end_pos is the same as
    /// setting pos to start_pos.
    ///
    memory_slot_t *pos;
} program_memory_t;

///
/// the operation that will be is executed.
///
typedef struct output_op {
    ///
    /// the operation bytecode
    ///
    byte_t code;

    ///
    /// the number of bytes that the instruction takes
    ///
    int bytecount;

    ///
    /// the arguments passed to the instruction
    ///
    args_t args[4];

    ///
    /// the number of arguments passed to the instruction
    ///
    int args_count;
} output_op_t;

struct operation {
    ///
    /// the bytecode of the operation
    ///
    byte_t code;

    ///
    /// the shorthand mnemotic of the operation
    ///
    char mnemo[6];

    ///
    /// op is the returned operation
    /// mem is the memory of the current program
    /// returns a bool true if an error occured
    ///
    bool (*parse_bytecode)(output_op_t *op, program_memory_t *mem);
};

#define COUNTOF(arr) (sizeof(arr) / sizeof(*arr))

#endif /* D2C3323B_231E_4734_9476_D89C4C20A637 */
