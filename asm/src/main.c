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

char *get_output_filename(char *input)
{
    char *output;
    int input_len = my_strlen(input);
    bool ends_with_s = my_str_endswith(input, ".s");

    if (ends_with_s) {
        output = malloc(sizeof(char) * (input_len + 3));
        if (output == NULL)
            return (NULL);
        my_strncpy(output, input, input_len - 2);
    } else {
        output = malloc(sizeof(char) * (input_len + 5));
        if (output == NULL)
            return (NULL);
        my_strncpy(output, input, input_len);
    }
    my_strcat(output, ".cor");
    return (output);
}

int main(int ac UNUSED, char *av[] UNUSED)
{
    char buffer[16384];
    int output_fd;
    char *output_file;

    if (ac != 2)
        return (84);
    output_file = get_output_filename(av[1]);
    if (output_file == NULL)
        return (84);
    output_fd = open(output_file, O_WRONLY | O_CREAT, 0644);
    if (read_file(buffer, av[1]) < 0) {
        my_dprintf(2, "Can't read file.\n");
        return (84);
    }
    close(output_fd);
    if (compile_string(output_fd, av[1], buffer) < 0)
        return (84);
    return (0);
}
