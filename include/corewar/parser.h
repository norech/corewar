/*
** EPITECH PROJECT, 2021
** parser
** File description:
** Source code
*/

#ifndef C842F867_2641_47BC_A0A8_F6CA40146510
#define C842F867_2641_47BC_A0A8_F6CA40146510

#include <corewar/corewar.h>

typedef struct group_args_s
{
    int prog_number;
    int load_address;
    char *name;
    bool has_load_address;
    bool has_prog_number;
    struct group_args_s *next;
} g_args_t;

typedef struct args_manager_s
{
    int nbr_cycle;
    bool debug_mode;
    g_args_t *g_args;
} args_t;

bool parse_bytecode(runtime_op_t *op, program_memory_t *mem);
int args_manager(int ac, char *av[], args_t *args);

char *read_next_value(int ac, char **av, int *i);
int loop_champions_args(int ac, char **av, int *index, args_t *args);

#define HELP_MESSAGE "USAGE\n\
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] \
...\n\
\n\
DESCRIPTION\n\
-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round \
isn't\n\
already over) with the following format: 32 bytes/line\n\
in hexadecimal (A0BCDEFE1DD3...)\n\
-n prog_number sets the next program's number. By default, the first free \
number\nin the parameter order\n\
-a load_address sets the next program's loading address. When no address is\n\
specified, optimize the addresses so that the processes are as far\n\
away from each other as possible. The addresses are MEM_SIZE modulo.\n"

#endif /* C842F867_2641_47BC_A0A8_F6CA40146510 */
