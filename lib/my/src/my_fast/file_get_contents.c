/*
** EPITECH PROJECT, 2021
** file_get_content
** File description:
** Source code
*/
#include <my/fast.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

intmax_t file_get_contents(char **output, char *file, int open_flag)
{
    int fd = open(file, open_flag);
    size_t size = 0;
    struct stat st;

    if (stat(file, &st) < 0)
        return (STAT_ERROR);
    size = st.st_size;
    *output = malloc(sizeof(char) * (size + 1));
    if (*output == NULL)
        return (MALLOC_ERROR);
    if (read(fd, *output, size) < 0)
        return (READ_ERROR);
    (*output)[size] = '\0';
    close(fd);
    return (size);
}