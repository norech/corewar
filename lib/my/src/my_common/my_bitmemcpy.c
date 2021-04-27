/*
** EPITECH PROJECT, 2020
** my_bit_memcpy
** File description:
** Source code
*/
#include <my.h>

static void copy_bytes(bit_address_t *element, bit_address_t *val,
    size_t bit_count)
{
    int offset = 7 - element->offset;
    int val_offset = 7 - val->offset;
    unsigned char *bytes = (unsigned char *)element->position;
    unsigned char *val_bytes = (unsigned char *)val->position;

    while (bit_count) {
        if (offset < 0) {
            bytes += 1;
            offset = 7;
        }
        if (val_offset < 0) {
            val_bytes += 1;
            val_offset = 7;
        }
        BITSET(*bytes, offset, BITGET(*val_bytes, val_offset));
        offset--;
        val_offset--;
        bit_count--;
    }
}

void my_bitmemcpy(bit_address_t *element, bit_address_t *val, size_t bit_count)
{
    element->position += element->offset / 8;
    element->offset = element->offset % 8;
    val->position += val->offset / 8;
    val->offset = val->offset % 8;
    copy_bytes(element, val, bit_count);
}