/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Reverse the input string
*/
#include <my.h>

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int real_len = len - 1;
    int i = 0;

    if (len % 2 != 0)
        len++;
    while (i < len / 2) {
        char tmp;
        tmp = str[i];
        str[i] = str[real_len - i];
        str[real_len - i] = tmp;
        i++;
    }
    return (str);
}
