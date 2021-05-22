/*
** EPITECH PROJECT, 2021
** main
** File description:
** Source code
*/

#include "corewar/op.h"
#include <my.h>
#include <my/io.h>
#include <asm/bytecode.h>
#include <asm/parser.h>
#include <asm/compiler.h>
#include <asm/util.h>
#include <fcntl.h>

int main(int ac UNUSED, char *av[] UNUSED)
{
    char buffer[16384];
    int output_fd = open(av[2], O_WRONLY | O_CREAT, 0644);

    if (read_file(buffer, av[1]) < 0) {
        my_dprintf(2, "Can't read file.\n");
        return (84);
    }
    if (compile_string(output_fd, av[1], buffer) < 0)
        return (84);
    return (0);
}