/*
** EPITECH PROJECT, 2020
** My Putchar
** File description:
** Putchar
*/
#include <my/io.h>

int write(int fd, const void *buf, int nbytes);

int my_fd_putchar(int fd, char c)
{
    return (write(fd, &c, 1));
}
