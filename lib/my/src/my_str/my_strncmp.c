/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Compare one string with another
*/
#include <my.h>

int my_strncmp(str_t s1, str_t s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s1[i] == s2[i] && i < n) {
        i++;
    }
    if (i == n)
        return (0);
    return (s1[i] - s2[i]);
}
