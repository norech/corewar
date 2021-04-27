/*
** EPITECH PROJECT, 2021
** main
** File description:
** Source code
*/

#include <my.h>
#include <my/io.h>
#include <asm/bytecode.h>
#include <fcntl.h>

int main(int ac UNUSED, char *av[] UNUSED)
{
    int fd = open("./sample.yolo", O_CREAT | O_WRONLY, 0644);

    bc_add(fd, 5, 5);
    bc_put(fd, "Henlo");
    close(fd);
}