/*
** EPITECH PROJECT, 2021
** get_error_message
** File description:
** Source code
*/

#include <my/fast.h>

char *get_error_message(int code)
{
    if (code >= 0)
        return (NULL);
    switch (code) {
        case STAT_ERROR:
            return ("Stat failed");
        case READ_ERROR:
            return ("Read failed");
        case MALLOC_ERROR:
            return ("Malloc failed");
        case BAD_SIZE_ERROR:
            return ("Bad size");
        default:
            return ("Unknown error");
    }
}