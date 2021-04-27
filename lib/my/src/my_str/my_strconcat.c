/*
** EPITECH PROJECT, 2020
** my_strconcat
** File description:
** Concats two or more strings together
*/
#include <my.h>
#include <stdarg.h>

mut_str_t my_strconcat(int argc, ...)
{
    va_list ap;
    str_t argv[argc + 1];
    int i = 0;

    va_start(ap, argc);
    for (; i < argc; i++)
        argv[i] = (char *)va_arg(ap, int *);
    va_end(ap);
    argv[i] = NULL;
    return (my_strjoin(argv, ""));
}
