/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** Source code
*/

#ifndef D2C3323B_231E_4734_9476_D89C4C20A637
#define D2C3323B_231E_4734_9476_D89C4C20A637

#include "corewar/op.h"
#include <stdlib.h>
#include <stdbool.h>

///
/// the type of argument
///
enum arg_type {
    ARG_DIR_NB = T_DIR,
    ARG_IND_NB = T_IND,
    ARG_REG_ID = T_REG
};

#define BYTES_TO_VALUE(bytes_array, type) \
    (*(type *) bytes_array)

#define GET_CODING_OF_ARG(coding_byte, id) \
    ((coding_byte >> (6 - 2 * id)) & 0b11)

typedef unsigned char arg_type_t;

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
    /// arg.dir_val or arg->dir_val
    ///
    union {
        dir_t dir_val;
        ind_t ind_val;
        reg_id_t reg_id;
    };

    ///
    /// The label attached to the value.
    /// Should only be used on the ASM parser!
    /// The VM is supposed to already have the labels resolved as dir_val or
    /// ind_val.
    ///
    char *label;
} arg_t;

typedef struct {
    byte_t data;
    byte_t owner;
} memory_slot_t;

///
/// the operation that will be is executed.
///
typedef struct runtime_op {
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
    arg_t args[4];

    ///
    /// the number of arguments passed to the instruction
    ///
    int args_count;
} runtime_op_t;

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

    ///
    /// registers.
    ///
    reg_data_t registers[REG_NUMBER - 1];

    ///
    /// the carry value
    ///
    bool carry;

    ///
    /// Number of cycles to sleep
    ///
    int sleep_cycles;
} program_memory_t;

typedef struct champion {

    ///
    /// The ID allocated by the VM
    ///
    int id;

    ///
    /// Name to display on live call
    ///
    char name[PROG_NAME_LENGTH + 1];

    ///
    /// Array of all instances
    /// Must be reallocated on fork if overflow.
    ///
    program_memory_t *instances;

    ///
    /// Number of instances created
    ///
    int instances_count;

    ///
    /// Number of instances that can be created before overflow
    ///
    int instances_max;
} champion_t;

typedef struct vm {
    champion_t *champions;
    int champions_count;
    program_memory_t memory;
} vm_t;

#define IS_INVALID_REGISTER_ID(id) \
    (id <= 0 || id > REG_NUMBER)

struct operation {
    ///
    /// the bytecode of the operation
    ///
    byte_t code;

    ///
    /// the shorthand mnemotic of the operation
    ///
    char mnemo[6];
};

static inline bool is_host_big_endian(void)
{
    unsigned short s = 0xFF00;
    byte_t *bytes = (byte_t *)&s;

    return (bytes[0] == 0xFF);
}

static inline bool is_arg_type_valid(byte_t opcode, int arg_index,
    enum arg_type arg_type)
{
    return ((OP_TAB[opcode].type[arg_index] & arg_type) != 0);
}

int next_step(vm_t *vm);

#define COUNTOF(arr) (sizeof(arr) / sizeof(*arr))

#endif /* D2C3323B_231E_4734_9476_D89C4C20A637 */
