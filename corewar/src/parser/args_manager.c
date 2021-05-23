/*
** EPITECH PROJECT, 2021
** args manager
** File description:
** Manage arguments
*/

#include <corewar/parser.h>
#include <my/str.h>
#include <my/io.h>
#include <my/common.h>

static int get_flag(int ac, char **av, int *i, args_t *args)
{
    char *key = NULL;

    if ((key = read_next_value(ac, av, i)) == NULL)
        return (84);
    if (my_strcmp(key, "-debug") != 0) {
        (*i)--;
        return (0);
    }
    args->debug_mode = true;
    return (0);
}

static int get_dump(int ac, char **av, int *i, args_t *args)
{
    char *key = NULL;
    char *value = NULL;

    if ((key = read_next_value(ac, av, i)) == NULL)
        return (84);
    if (my_strcmp(key, "-dump") != 0) {
        (*i)--;
        return (0);
    }
    if ((value = read_next_value(ac, av, i)) == NULL)
        return (84);
    if (!my_str_isnum(value))
        return (84);
    args->nbr_cycle = my_getnbr(value).value;
    return (0);
}

int args_manager(int ac, char *av[], args_t *args)
{
    int index = 1;
    int code;

    if (ac == 2 && (my_strcmp(av[1], "-h") == 0)) {
        my_fd_putstr(1, HELP_MESSAGE);
        return (0);
    }
    if (get_flag(ac, av, &index, args) == 84)
        return (84);
    if (get_dump(ac, av, &index, args) == 84)
        return (84);
    if (get_flag(ac, av, &index, args) == 84)
        return (84);
    code = loop_champions_args(ac, av, &index, args);
    if (index != ac)
        return (84);
    return (code);
}