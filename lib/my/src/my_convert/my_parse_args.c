/*
** EPITECH PROJECT, 2020
** my_parse_args
** File description:
** Source code
*/

#include <my.h>
#include <stdlib.h>

static void append_flags(char *flags, char const *input)
{
    int i = my_strlen(flags);
    while (*input != '\0') {
        if (i >= 255)
            return;
        if (!my_char_in(flags, *input)) {
            flags[i] = *input;
            i++;
        }
        input++;
    }
}

static int count_args(int argc, char **argv)
{
    char *arg;
    int i = 0;
    int count = 0;

    while (i < argc) {
        arg = argv[i];
        if (*arg != '-')
            count++;
        i++;
    }
    return (count);
}

static void fill(int argc, char **argv, char *flags, char **args)
{
    int i = 0;
    int j = 0;
    char *arg;

    my_memset(flags, 0, 256);
    while (i <= argc) {
        arg = argv[i];
        if (*arg == '-') {
            append_flags(flags, arg + 1);
        } else {
            args[j] = arg;
            j++;
        }
        i++;
    }
    args[j] = NULL;
}

parsed_args_t my_parse_args(int argc, char **argv)
{
    int args_count = count_args(argc, argv);
    char *flags = malloc(sizeof(char) * 256);
    char **args = malloc(sizeof(char *) * (args_count + 1));

    if (flags == NULL || args == NULL)
        return ((parsed_args_t) { 0, NULL, NULL });
    fill(argc, argv, flags, args);
    return ((parsed_args_t) { args_count, args, flags });
}
