/*
** EPITECH PROJECT, 2021
** bc_put
** File description:
** Source code
*/

#include <unistd.h>
#include <corewar/op.h>
#include <my/str.h>

void bc_put(int fd, char *word)
{
    unsigned char code = OP_PUT;
    int len = sizeof(char) * my_strlen(word);

    write(fd, &code, sizeof(code));
    write(fd, &len, sizeof(len));
    write(fd, word, len);
}