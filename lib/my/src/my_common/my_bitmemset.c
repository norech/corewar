/*
** EPITECH PROJECT, 2020
** my_bit_memset
** File description:
** Source code
*/
#include <my.h>

static void fill_bytes(void *element, int startoffset, size_t bit_count,
    bool value)
{
    int offset = 7 - startoffset;
    unsigned char *bytes = (unsigned char *)element;

    bit_count--;
    while (bit_count + 1) {
        if (offset < 0) {
            bytes += 1;
            offset = 7;
        }
        BITSET(*bytes, offset, value);
        offset--;
        bit_count--;
    }
}

void my_bitmemset(void *element, int startoffset, bool value, size_t bit_count)
{
    element += startoffset / 8;
    startoffset = startoffset % 8;
    fill_bytes(element, startoffset, bit_count, value);
}