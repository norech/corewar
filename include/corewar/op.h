/*
** EPITECH PROJECT, 2021
** op
** File description:
** Source code
*/

#ifndef F0FDE37D_FFB1_46A6_8733_52016F7FF56D
#define F0FDE37D_FFB1_46A6_8733_52016F7FF56D

#include <corewar/corewar.h>

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

#define MEM_SIZE                (6*1024)

///
/// modulo of the index
///
#define IDX_MOD                 512
///
/// this may not be changed 2^*IND_SIZE
///
#define MAX_ARGS_NUMBER         4

#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','

#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING         ".name"
#define COMMENT_CMD_STRING      ".comment"

#define REG_NUMBER      16              /* r1 <--> rx */

typedef char args_type_t;

///
/// register
///
#define T_REG           1

///
/// direct  (ld  #1,r1  put 1 into r1)
///
#define T_DIR           2

///
/// indirect always relative
/// ( ld 1,r1 put what's in the address (1+pc)
/// into r1 (4 bytes ))
///
#define T_IND           4

///
/// LABEL
///
#define T_LAB           8

struct op_s
{
    char         *mnemo;
    char         args_count;
    args_type_t  type[MAX_ARGS_NUMBER];
    char         code;
    int          cycles_count;
    char         *comment;
};

typedef struct op_s     op_t;

#define IND_SIZE        2
#define DIR_SIZE        4
#define REG_SIZE        DIR_SIZE

extern  op_t    OP_TAB[];

#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048

#define COREWAR_EXEC_MAGIC      0xea83f3

struct header_s
{
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int  prog_size;
    char comment[COMMENT_LENGTH + 1];
};

typedef struct header_s header_t;

#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40

#endif /* F0FDE37D_FFB1_46A6_8733_52016F7FF56D */
