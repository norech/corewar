/*
** EPITECH PROJECT, 2020
** my_fd_getnextline.c
** File description:
** getnextline
*/

#include <my.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

char *my_fd_getnextline(int fd)
{
    char buffer;
    char *tmp;
    char *output = my_strdup("");
    int readed = 0;

    while ((readed = read(fd, &buffer, 1)) > 0) {
        if (buffer == '\n')
            break;
        tmp = output;
        output = malloc(sizeof(char) * (my_strlen(output) + 2));
        if (output == NULL)
            return (free(tmp), NULL);
        my_strcpy(output, tmp);
        my_strncat(output, &buffer, 1);
        free(tmp);
    }
    if (readed == 0 && *output == '\0') {
        free(output);
        return (NULL);
    }
    return (output);
}
