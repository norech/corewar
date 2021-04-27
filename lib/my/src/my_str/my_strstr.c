/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Search a string in another
*/
#include <my.h>
#include <my/types.h>

strpos_t my_strstr(str_t str, str_t to_find)
{
    int i = 0;
    int j = 0;
    bool is_end;

    if (my_strncmp(str, to_find, my_strlen(to_find)) == 0)
            return (&str[0]);
    while (str[i] != '\0') {
        j = 0;
        is_end = (to_find[j] == '\0' || str[i + j] == '\0');
        while (!is_end && str[i + j] == to_find[j]) {
            j++;
        }
        if (to_find[j] == '\0')
            return (&str[i]);
        i++;
    }
    return (NULL);
}
