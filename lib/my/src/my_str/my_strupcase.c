/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** Put str to upcase
*/
#include <my.h>

char *my_strupcase(char *str)
{
    int i = 0;
    while (i < my_strlen(str)) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }

    return (str);
}
