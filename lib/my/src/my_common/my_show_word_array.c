/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** Shows word array
*/

#include <my.h>
#include <stdlib.h>

int my_show_word_array(char const **elements)
{
    int i = 0;
    while (elements[i]) {
        my_putstr(elements[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
