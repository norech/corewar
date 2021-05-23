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

g_args_t *get_max(args_t *args)
{
    g_args_t *tmp = args->g_args;

    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

g_args_t *new()
{
    g_args_t *tmp = malloc(sizeof(g_args_t));

    tmp->load_address = 0;
    tmp->name = NULL;
    tmp->next = NULL;
    tmp->prog_number = 0;
    return (tmp);
}

int group_args(char *av[], int *i, args_t *args)
{
    if (my_strcmp(av[*i], "-n") == 0) {
        if (av[*i + 1] && my_str_isnum(av[*i + 1])) {
            get_max(args)->prog_number = my_getnbr(av[*i + 1]).value;
            *i += 2;
        } else
            return 84;
    }
    if (my_strcmp(av[*i], "-a") == 0) {
        if (av[*i + 1] && my_str_isnum(av[*i + 1])) {
            get_max(args)->load_address = my_getnbr(av[*i + 1]).value;
            *i += 2;
        } else
            return 84;
    }
    if (av[*i] && my_strncmp(av[*i], "-", 1) != 0) {
        get_max(args)->name = av[*i];
    }
    get_max(args)->next = new();
    return 0;
}

int other_args(char *av[], args_t *args)
{
    args->g_args = new();
    for (int i = 1; av[i]; i++) {
        if ((my_strcmp(av[i], "-dump") == 0) && av[i + 1]) {
            if (my_str_isnum(av[i + 1])) {
                args->nbr_cycle = my_getnbr(av[i + 1]).value;
                i += 2;
            } else {
                my_fd_putstr(2, "Dump value is not a number.");
                return (84);
            }
        }
        if ((my_strcmp(av[i], "-n") == 0) || (my_strcmp(av[i], "-a") == 0) ||
        my_strncmp(av[i], "-", 1) != 0) {
            if (group_args(av, &i, args) == 84)
                return 84;
        }
    }
    return 0;
}

int args_manager(int ac, char *av[], args_t *args)
{
    if ((my_strcmp(av[1], "-h") == 0) && ac == 2) {
        my_fd_putstr(1, HELP_MESSAGE);
        return (0);
    }
    return (other_args(av, args));
}