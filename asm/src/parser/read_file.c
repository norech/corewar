/*
** EPITECH PROJECT, 2021
** create_parser_from_file
** File description:
** Source code
*/

#include "corewar/op.h"
#include <my.h>
#include <my/io.h>
#include <asm/bytecode.h>
#include <asm/parser.h>
#include <asm/util.h>
#include <fcntl.h>

int read_file(char *output_buffer, char *file)
{
    int fd = open(file, O_RDONLY);
    int readed;

    if (fd == 0)
        return (-1);
    readed = read(fd, output_buffer, 16383);
    if (readed == 16383 || readed < 0)
        return (-1);
    close(fd);
    output_buffer[readed] = '\0';
    return (0);
}