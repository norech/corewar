##
## EPITECH PROJECT, 2020
## libmy
## File description:
## My library
##

CC = gcc

AR_RC ?= ar rc

LN_RSF ?= ln -rsf

CFLAGS = -W -Wall -Werror -I./include -g $(LIB_GCC_ARGS)

CFLAGS_TEST = $(CFLAGS) -Wno-stringop-truncation -Wno-error=format -lcriterion --coverage

LFLAGS = \

LFLAGS_TEST = $(LFLAGS) -lcriterion

TESTDIR = ../../tests/lib/my

SRC_COMMON =	\
	src/my_common/my_free_array.c \
	src/my_common/my_get_digit_char.c \
	src/my_common/my_getnbr.c \
	src/my_common/my_numlen.c \
	src/my_common/my_putchar.c \
	src/my_common/my_put_digit.c \
	src/my_common/my_put_float.c \
	src/my_common/my_put_nbr.c \
	src/my_common/my_put_u_nbr.c \
	src/my_common/my_put_nbr_base.c \
	src/my_common/my_intlen.c \
	src/my_common/my_longlen.c \
	src/my_common/my_longlonglen.c \
	src/my_common/my_float_to_exponent.c \
	src/my_common/my_size_t_len.c \
	src/my_common/my_putstr.c \
	src/my_common/my_showmem.c \
	src/my_common/my_showstr.c \
	src/my_common/my_show_word_array.c \
	src/my_common/my_sort_int_array.c \
	src/my_common/my_swap.c \
	src/my_common/my_swap_ptr.c \
	src/my_common/my_round_float.c \
	src/my_common/my_calloc.c \
	src/my_common/my_memcpy.c \
	src/my_common/my_memset.c \
	src/my_common/my_bitmemset.c \
	src/my_common/my_bitmemcpy.c \
	src/my_common/my_strarray_size.c \
	src/my_common/my_strarray_free.c

SRC_CONVERT = \
	src/my_convert/my_itoa.c \
	src/my_convert/my_uitoa.c \
	src/my_convert/my_ultoa.c \
	src/my_convert/my_ltoa.c \
	src/my_convert/my_lltoa.c \
	src/my_convert/my_size_t_to_string.c \
	src/my_convert/my_parse_args.c

SRC_DEBUG = \
	src/my_debug/array/my_array_print_nbarr.c \
	src/my_debug/array/my_array_print_strarr.c \
	src/my_debug/array/my_array_print_floatarr.c

SRC_MATH = \
	src/my_math/my_pow.c \
	src/my_math/my_sqrt.c \
	src/my_math/my_find_prime_sup.c \
	src/my_math/my_is_prime.c \

SRC_IO = \
	src/my_fd/my_fd_put_digit.c \
	src/my_fd/my_fd_putchar.c \
	src/my_fd/my_fd_putstr.c \
	src/my_fd/my_fd_put_float.c \
	src/my_fd/my_fd_put_nbr_base.c \
	src/my_fd/my_fd_put_nbr.c \
	src/my_fd/my_fd_put_u_nbr.c \

SRC_FORMAT = \
	src/my_printf/my_printf.c \
	src/my_printf/my_dprintf.c \
	src/my_printf/my_printf_convert.c \
	src/my_printf/my_printf_parse_flags.c \
	src/my_printf/my_printf_parse_tokens.c \
	src/my_printf/my_printf_put_exp_lower.c \
	src/my_printf/my_printf_put_exp_upper.c \
	src/my_printf/my_printf_put_float.c \
	src/my_printf/my_printf_put_percent.c \
	src/my_printf/my_printf_put_nbr.c \
	src/my_printf/my_printf_put_unsigned_nbr.c \
	src/my_printf/my_printf_putchar.c \
	src/my_printf/my_printf_putstr.c \
	src/my_printf/my_printf_putstr_printable.c \
	src/my_printf/my_printf_put_binary.c \
	src/my_printf/my_printf_put_octal.c \
	src/my_printf/my_printf_put_hexa_lower.c \
	src/my_printf/my_printf_put_hexa_upper.c \
	src/my_printf/my_printf_putptr.c

SRC_ARRAY = \
	src/my_array/my_array_count.c \
	src/my_array/my_array_merge.c \
	src/my_array/my_array_find_one.c \
	src/my_array/my_array_find_all.c \
	src/my_array/my_arraydup.c \
	src/my_array/my_array_qsort.c \
	src/my_array/my_array_swap.c \
	src/my_array/cmp/with_value.c

SRC_LINKED_LIST = \
	src/my_linked_list/my_count_nodes.c \
	src/my_linked_list/my_find_previous_node.c \
	src/my_linked_list/my_get_last_node.c \
	src/my_linked_list/my_get_node_index.c \
	src/my_linked_list/my_insert_node.c \
	src/my_linked_list/my_pop_node.c \
	src/my_linked_list/my_push_node.c \
	src/my_linked_list/my_detach_node.c \
	src/my_linked_list/my_remove_node.c \
	src/my_linked_list/my_reverse_node.c \
	src/my_linked_list/my_shift_node.c \
	src/my_linked_list/my_swap_node_and_next.c \
	src/my_linked_list/my_unshift_node.c

SRC_STR = \
	src/my_str/my_bzero.c \
	src/my_str/my_char_in.c \
	src/my_str/my_revstr.c \
	src/my_str/my_strpad_start.c \
	src/my_str/my_strpad_end.c \
	src/my_str/my_strcapitalize.c \
	src/my_str/my_str_startswith.c \
	src/my_str/my_str_endswith.c \
	src/my_str/my_str_repeat.c \
	src/my_str/my_strcat.c \
	src/my_str/my_strcmp.c \
	src/my_str/my_strcpy.c \
	src/my_str/my_strdup.c \
	src/my_str/my_strndup.c \
	src/my_str/my_strlen.c \
	src/my_str/my_strlowcase.c \
	src/my_str/my_strncat.c \
	src/my_str/my_strncmp.c \
	src/my_str/my_strncpy.c \
	src/my_str/my_strsplit.c \
	src/my_str/my_strstr.c \
	src/my_str/my_strupcase.c \
	src/my_str/my_str_filter.c \
	src/my_str/my_strinvertcase.c \
	src/my_str/my_str_isalpha.c \
	src/my_str/my_str_islower.c \
	src/my_str/my_str_isnum.c \
	src/my_str/my_str_isprintable.c \
	src/my_str/my_str_isupper.c \
	src/my_str/my_strjoin.c \
	src/my_str/my_strsplit_fnc.c \
	src/my_str/my_strconcat.c \
	src/my_str/my_strcount.c \
	src/my_str/my_strtake.c

SRC_STRING = \
	src/my_string/my_string_append.c \
	src/my_string/my_string_assign.c \
	src/my_string/my_string_compare.c \
	src/my_string/my_string_create.c \
	src/my_string/my_string_create_raw.c \
	src/my_string/my_string_create_with_capacity.c \
	src/my_string/my_string_destroy.c \
	src/my_string/my_string_from_capacity.c \
	src/my_string/my_string_from.c \
	src/my_string/my_string_indexof.c \
	src/my_string/my_string_pop.c \
	src/my_string/my_string_push_str.c \
	src/my_string/my_string_push.c \
	src/my_string/my_string_reserve.c

OBJ_DEBUG = $(SRC_DEBUG:.c=.o)
OBJ_CONVERT = $(SRC_CONVERT:.c=.o)
OBJ_COMMON = $(SRC_COMMON:.c=.o)
OBJ_MATH = $(SRC_MATH:.c=.o)
OBJ_IO = $(SRC_IO:.c=.o)
OBJ_FORMAT = $(SRC_FORMAT:.c=.o)
OBJ_ARRAY = $(SRC_ARRAY:.c=.o)
OBJ_LINKED_LIST = $(SRC_LINKED_LIST:.c=.o)
OBJ_STR = $(SRC_STR:.c=.o)
OBJ_STRING = $(SRC_STRING:.c=.o)

SRC_ALL = \
	$(SRC_COMMON) \
	$(SRC_CONVERT) \
	$(SRC_DEBUG) \
	$(SRC_MATH) \
	$(SRC_IO) \
	$(SRC_LINKED_LIST) \
	$(SRC_FORMAT) \
	$(SRC_ARRAY) \
	$(SRC_STR) \
	$(SRC_STRING)

OBJ_ALL = $(SRC:.c=.o)

SRC = 
OBJ = 

TEST_FILES = \
	$(TESTDIR)/test_my_printf.c \
	$(TESTDIR)/test_my_strconcat.c \
	$(TESTDIR)/test_my_putchar.c \
	$(TESTDIR)/test_my_revstr.c \
	$(TESTDIR)/test_my_strcapitalize.c \
	$(TESTDIR)/test_my_strcat.c \
	$(TESTDIR)/test_my_strcmp.c \
	$(TESTDIR)/test_my_strcpy.c \
	$(TESTDIR)/test_my_strdup.c \
	$(TESTDIR)/test_my_strsplit.c \
	$(TESTDIR)/test_my_strjoin.c \
	$(TESTDIR)/test_my_str_isalpha.c \
	$(TESTDIR)/test_my_str_islower.c \
	$(TESTDIR)/test_my_str_isnum.c \
	$(TESTDIR)/test_my_str_isprintable.c \
	$(TESTDIR)/test_my_str_isupper.c \
	$(TESTDIR)/test_my_strlowcase.c \
	$(TESTDIR)/test_my_strncat.c \
	$(TESTDIR)/test_my_strncmp.c \
	$(TESTDIR)/test_my_strncpy.c \
	$(TESTDIR)/test_my_strstr.c \
	$(TESTDIR)/test_my_strupcase.c\
	$(TESTDIR)/test_my_strcount.c\
	$(TESTDIR)/test_my_str_startswith.c\
	$(TESTDIR)/test_my_str_endswith.c\
	$(TESTDIR)/test_my_array_count.c \
	$(TESTDIR)/test_my_array_merge.c \
	$(TESTDIR)/test_my_array_find.c \
	$(TESTDIR)/test_BITSET.c\
	$(TESTDIR)/test_BITGET.c\
	$(TESTDIR)/test_my_bitmemset.c \
	$(TESTDIR)/test_my_bitmemcpy.c \
	$(TESTDIR)/test_my_count_nodes.c \
	$(TESTDIR)/test_my_find_previous_node.c \
	$(TESTDIR)/test_my_get_last_node.c \
	$(TESTDIR)/test_my_remove_node.c \
	$(TESTDIR)/my_string/test_my_string_append.c \
	$(TESTDIR)/my_string/test_my_string_create.c \
	$(TESTDIR)/my_string/test_my_string_compare.c \
	$(TESTDIR)/my_string/test_my_string_indexof.c \
	$(TESTDIR)/my_string/test_my_string_push_str.c \
	$(TESTDIR)/my_string/test_my_string_assign.c

TARGET = libmy.a

TARGET_TEST = unit_tests

ifeq ("$(LIB_COMMON)","1")
	SRC += $(SRC_COMMON)
	OBJ += $(OBJ_COMMON)
endif
ifeq ("$(LIB_DEBUG)","1")
	SRC += $(SRC_DEBUG)
	OBJ += $(OBJ_DEBUG)
	LIB_ARRAY = 1
	LIB_FORMAT = 1
endif
ifeq ("$(LIB_FORMAT)","1")
	SRC += $(SRC_FORMAT)
	OBJ += $(OBJ_FORMAT)
	LIB_STR = 1
	LIB_CONVERT = 1
	LIB_IO = 1
endif
ifeq ("$(LIB_IO)","1")
	SRC += $(SRC_IO)
	OBJ += $(OBJ_IO)
endif
ifeq ("$(LIB_MATH)","1")
	SRC += $(SRC_MATH)
	OBJ += $(OBJ_MATH)
endif
ifeq ("$(LIB_ARRAY)","1")
	SRC += $(SRC_ARRAY)
	OBJ += $(OBJ_ARRAY)
endif
ifeq ("$(LIB_LINKED_LIST)","1")
	SRC += $(SRC_LINKED_LIST)
	OBJ += $(OBJ_LINKED_LIST)
endif
ifeq ("$(LIB_STR)","1")
	SRC += $(SRC_STR)
	OBJ += $(OBJ_STR)
endif
ifeq ("$(LIB_STRING)","1")
	SRC += $(SRC_STRING)
	OBJ += $(OBJ_STRING)
	LIB_STR = 1
endif
ifeq ("$(LIB_CONVERT)","1")
	SRC += $(SRC_CONVERT)
	OBJ += $(OBJ_CONVERT)
endif

ifeq ("$(SRC)","")
	SRC = $(SRC_ALL)
	OBJ = $(OBJ_ALL)
	LIB_ALL = 1
endif

all: build_all

copy_headers:
	@mkdir -p ../../include
	@$(LN_RSF) ./include/my.h ../../include
	@$(LN_RSF) ./include/my ../../include

build_all: $(OBJ)
	$(AR_RC) $(TARGET) $(OBJ)
	cp $(TARGET) ../
	@echo "Copying headers..."
	$(MAKE) copy_headers

tests_run: clean_tests
	$(CC) $(CFLAGS) $(CFLAGS_TEST) -o $(TARGET_TEST) $(SRC_ALL) $(TEST_FILES) $(LFLAGS)
	./$(TARGET_TEST)

clean_tests:
	rm -rf *.gc* $(TARGET_TEST)

coverage: tests_run
	gcovr

clean:
	rm -f $(OBJ) *.gc* unit_test

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all re tests_run coverage clean fclean