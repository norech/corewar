/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Copy one string to another
*/
#include <my.h>

mut_str_t my_strcpy(mut_str_t dest, str_t src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
