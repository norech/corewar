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

char *read_next_value(int ac, char **av, int *i)
{
    char *value;
    if (*i >= ac)
        return (NULL);
    value = av[*i];
    (*i)++;
    return (value);
}

int parse_value(char *key, char *value, g_args_t *last_arg)
{
    if (my_strcmp(key, "-a") == 0) {
        if (!my_str_isnum(value))
            return (84);
        last_arg->load_address = my_getnbr(value).value;
        last_arg->has_load_address = true;
    }
    if (my_strcmp(key, "-n") == 0) {
        if (!my_str_isnum(value))
            return (84);
        last_arg->prog_number = my_getnbr(value).value;
        last_arg->has_prog_number = true;
    }
    return (0);
}

int add_to_args(g_args_t **last_arg, char *key)
{
    g_args_t *prev = *last_arg;

    *last_arg = my_calloc(1, sizeof(g_args_t));
    if (*last_arg == NULL)
        return (84);
    prev->next = *last_arg;
    prev->name = key;
    return (0);
}

int loop_champions_args(int ac, char **av, int *index, args_t *args)
{
    char *key = NULL;
    char *value = NULL;
    g_args_t *last_arg = my_calloc(1, sizeof(g_args_t));

    args->g_args = last_arg;
    if (last_arg == NULL)
        return (84);
    while (true) {
        if ((key = read_next_value(ac, av, index)) == NULL)
            break;
        if (*key != '-') {
            if (add_to_args(&last_arg, key) == 84)
                return (84);
            continue;
        } else if ((value = read_next_value(ac, av, index)) == NULL
            || parse_value(key, value, last_arg) == 84)
                return (84);
    }
    return (0);
}