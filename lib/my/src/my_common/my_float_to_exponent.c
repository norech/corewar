/*
** EPITECH PROJECT, 2020
** my_float_to_exponent
** File description:
** Source code
*/

float my_float_to_exponent(float number, int *exponent)
{
    *exponent = 0;
    while (number < 1.0) {
        number *= 10;
        (*exponent)--;
    }
    while (number >= 10.0) {
        number /= 10;
        (*exponent)++;
    }
    return (number);
}