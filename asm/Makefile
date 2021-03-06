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

SRC_GENERATOR = src/generator/init_generator.c \
				src/generator/generate_code.c \

SRC_UTIL = 		src/util/write_endian.c \
				src/util/write_endian_offset.c \
				src/util/write_reversed.c \
				src/util/push_instruction.c \
				src/util/pop_instruction.c \
				src/util/get_line_num.c \
				src/util/distance_between_instructions.c \
				src/util/swap_header.c \

SRC_PARSER = 	src/parser/parser.c \
				src/parser/parser_args.c \
				src/parser/parser_labels.c \
				src/parser/parser_error.c \
				src/parser/read_file.c \
				src/parser/init_parser.c	\
				src/parser/comment.c

SRC_ANALYZER = 	src/analyzer/analyzer.c \
				src/analyzer/analyzer_error.c \
				src/analyzer/init_analyzer.c \
				src/analyzer/analyzer/analyze_labels.c \
				src/analyzer/analyzer/analyze_signature.c \
				src/analyzer/analyzer/analyze_size.c \

SRC_CONSUMERS = src/parser/consumers/consume_arg_label.c \
				src/parser/consumers/consume_comma.c \
				src/parser/consumers/consume_instruction_mnemo.c \
				src/parser/consumers/consume_newlines.c \
				src/parser/consumers/consume_number.c \
				src/parser/consumers/consume_label.c \
				src/parser/consumers/consume_whitespaces.c	\
				src/parser/consumers/consume_arg_name.c	\
				src/parser/consumers/consume_comment.c \

SRC_COMPILER =	src/compiler.c \
				src/compiler_error.c

SRC =	$(SRC_BYTECODE) \
		$(SRC_UTIL) \
		$(SRC_PARSER) \
		$(SRC_CONSUMERS) \
		$(SRC_GENERATOR) \
		$(SRC_COMPILER) \
		$(SRC_ANALYZER) \
		../corewar/src/op.c

TESTS =	\

OBJ_TESTS = $(SRC:.c=.o) $(TESTS:.c=.o)

OBJ = $(SRC:.c=.o) src/main.o

all: build_lib
	${MAKE} -j build_all -C .

build_lib:
	$(LIB_MODULES) $(MAKE) -j -C ../lib/my/

build_all: ${OBJ}
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LFLAGS)

tests_run: clean_tests build_lib ${OBJ_TESTS}
	$(CC) $(CFLAGS) $(TEST_FLAGS) -o $(TARGET_TEST) $(OBJ_TESTS) $(LFLAGS)
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
	rm -f $(OBJ)
	rm -f *.gc* unit_tests

re: fclean all
