CC = gcc

CFLAGS = -W -Wall -Werror -I../include -L../lib -DCOREWAR_ASM -DSOFT_TYPES

ifeq ($(EPIDEBUG), 1)
	CFLAGS += -Wno-error=init-self -Winit-self
	CFLAGS += -Wno-error=shadow -Wshadow
	CFLAGS += -Wno-error=pointer-arith -Wpointer-arith
	CFLAGS += -Wno-error=duplicated-cond -Wduplicated-cond
	CFLAGS += -Wno-error=switch-enum -Wswitch-enum
	CFLAGS += -Wno-error=declaration-after-statement -Wdeclaration-after-statement
	CFLAGS += -Wno-error=float-equal -Wfloat-equal
	CFLAGS += -Wno-error=tautological-compare -Wtautological-compare
	CFLAGS += -Wno-error=array-bounds -Warray-bounds
	CFLAGS += -Wno-error=alloc-zero -Walloc-zero
	CFLAGS += -Wno-error=cast-qual -Wcast-qual
	CFLAGS += -Wno-error=extra -Wextra
	CFLAGS += -fno-builtin
	CFLAGS += -ftrapv -ggdb -g3
endif

ifeq ($(SAN), 1)
	CFLAGS += -fsanitize=address,bounds,undefined,float-divide-by-zero,pointer-overflow
endif

LFLAGS = -lmy

TEST_FLAGS = $(LFLAGS) -lcriterion --coverage -Wno-declaration-after-statement

LIB_MODULES = \
	LIB_FAST=1 \
	LIB_ARRAY=1 \
	LIB_COMMON=1 \
	LIB_FORMAT=1 \
	LIB_DEBUG=1 \
	LIB_GCC_ARGS=""

TARGET = asm

TARGET_TEST = unit_tests

SRC_BYTECODE = 	src/generator/bytecode/bc_coding_byte.c \
				src/generator/bytecode/bc_zjmp.c \

SRC_UTIL = 		src/util/write_endian.c \
				src/util/write_reversed.c \
				src/util/push_instruction.c \
				src/util/pop_instruction.c \
				src/util/get_line_num.c \

SRC_PARSER = 	src/parser/parser.c \
				src/parser/parser_error.c

SRC_CONSUMERS = src/parser/consumers/consume_arg_label.c \
				src/parser/consumers/consume_comma.c \
				src/parser/consumers/consume_instruction_mnemo.c \
				src/parser/consumers/consume_newlines.c \
				src/parser/consumers/consume_number.c \
				src/parser/consumers/consume_whitespaces.c

SRC =	$(SRC_BYTECODE) \
		$(SRC_UTIL) \
		$(SRC_PARSER) \
		$(SRC_CONSUMERS) \
		../corewar/src/op.c

TESTS =	\

all: build_lib build_all

build_lib:
	$(LIB_MODULES) $(MAKE) -C ../lib/my/

build_all: $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) src/main.c $(LFLAGS)

tests_run: clean_tests build_lib
	$(CC) $(CFLAGS) $(TEST_FLAGS) -o $(TARGET_TEST) $(SRC) $(TESTS) $(LFLAGS)
	./$(TARGET_TEST) --verbose

coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

clean_tests:
	rm -rf $(TARGET_TEST)

$(TARGET): build_all

clean:
	rm -f $(TARGET)

fclean: clean
	$(MAKE) -C ../lib/my/ fclean
	rm -f *.gc* unit_tests

re: fclean all
