/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** Put str to lowcase
*/
#include <my.h>

char *my_strlowcase(char *str)
{
    int i = 0;
    while (i < my_strlen(str)) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }

    return (str);
}
