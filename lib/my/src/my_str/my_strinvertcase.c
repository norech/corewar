/*
** EPITECH PROJECT, 2020
** my_strinvertcase
** File description:
** Invert the case
*/
#include <my.h>

char *my_strinvertcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 32);
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] + 32);
        }
        i++;
    }
    return (str);
}
