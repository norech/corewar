/*
** EPITECH PROJECT, 2020
** My Putchar
** File description:
** Putchar
*/

int write(int fd, const void *buf, int nbytes);

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
