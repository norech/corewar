/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Compare one string with another
*/
#include <my.h>

int my_strcmp(str_t s1, str_t s2)
{
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        if (s1[i] > s2[i])
            return (1);
        return (-1);
    }
    return (0);
}
