/*
** EPITECH PROJECT, 2021
** common
** File description:
** Source code
*/

#ifndef MY_COMMON_H
#define MY_COMMON_H
#include <my/result.h>
#include <my.h>

typedef struct parsed_args {
    int argc;
    char **argv;
    char *flags;
} parsed_args_t;

RES(int)      my_getnbr(char const *str);

void         *my_calloc(int size, int count);

int           my_putchar(char c);

int           my_put_digit(int i);

int           my_put_nbr(long long nb);

int           my_put_u_nbr(unsigned long long nb);

int           my_put_nbr_base(long long nb, int radix);

int           my_uitoa(char *output, unsigned int nb, int radix);

int           my_ultoa(char *output, unsigned long nb, int radix);

int           my_itoa(char *output, int nb, int radix);

int           my_ltoa(char *output, long nb, int radix);

int           my_lltoa(char *output, long long int nb, int radix);

int           my_size_t_to_string(char *output, size_t nb, int radix);

int           my_ucharlen(unsigned char number, int radix);

int           my_intlen(int number, int base);

int           my_longlen(long number, int base);

int           my_longlonglen(long long number, int base);

int           my_size_t_len(size_t number, int base);

void          my_swap(int *a, int *b);

int           my_putstr(char const *str);

void          my_sort_int_array(int *tab, int size);

int           my_showstr(char const *str);

int           my_showmem(char const *str, int size);

int           my_numlen(int number);

char          my_get_digit_char(int i);

int           my_show_word_array(char const **elements);

float         my_float_to_exponent(float number, int *exponent);

int           my_put_float(float nb, int digits);

float         my_round_float(float nb, int digits);

void          my_swap_ptr(void **e1, void **e2);

void          my_free_array(void **array);

parsed_args_t my_parse_args(int argc, char **argv);

void         *my_memset(void *dest, char fill, size_t size);

void         *my_memcpy(void *dest, void *val, size_t size);

void          my_bitmemset(void *element, int startoffset, bool value,
                size_t bit_count);

void          my_bitmemcpy(bit_address_t *target, bit_address_t *src,
                size_t bit_count);

int           my_strarray_size(char **args);

void          my_strarray_free(char **array);

#endif //MY_COMMON_H