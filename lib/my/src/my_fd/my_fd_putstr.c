/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Puts a string
*/
#include <my/io.h>

int my_fd_putstr(int fd, char const *str)
{
    char *chr = (char *) str;
    int len = 0;

    while (*chr != '\0') {
        if (my_fd_putchar(fd, *chr) < 0)
            break;
        chr++;
        len++;
    }
    return (len);
}
