CC = gcc

CFLAGS = -W -Wall -Werror -I../include -L../lib -DCOREWAR_VM -DSOFT_TYPES

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

TARGET = corewar

TARGET_TEST = unit_tests

SRC_DATATYPE = 	src/datatype/fetch_byte.c \
				src/datatype/fetch_dir.c \
				src/datatype/fetch_ind.c \
				src/datatype/fetch_reg.c \
				src/datatype/resolve_arg_value.c \

SRC_DEBUG = 	src/debug/debug_and_pause.c \
				src/debug/diff_memory.c \
				src/debug/dump_memory.c \
				src/debug/print_op.c \

SRC_MEMORY = 	src/memory/copy_relative_bytes.c \
				src/memory/copy_relative_endian_bytes.c \
				src/memory/jump_relative_bytes.c \
				src/memory/write_relative_bytes.c \
				src/memory/write_relative_endian_bytes.c \

SRC_PARSER =	src/parser/parse_bytecode.c \

SRC_INSTRUCT = 	src/instructions/aff.c \
				src/instructions/fork.c \
				src/instructions/live.c \
				src/instructions/zjmp.c \
				src/instructions/and.c	\
				src/instructions/add.c	\
				src/instructions/or.c	\
				src/instructions/xor.c  \
				src/instructions/sub.c \
				src/instructions/lfork.c \
				src/instructions/st.c \
				src/instructions/sti.c \
				src/instructions/ld.c \

SRC_UTIL =		src/util/alloc_memory.c \
				src/util/init_memory.c \
				src/util/move_to_champion_pos.c \
				src/util/append_instance.c \
				src/util/swap_header.c \

SRC_CHAMPION = 	src/champion/create_champion.c \
				src/champion/load_champion_from_file.c \
				src/champion/load_champion_from_bytes.c

SRC =	$(SRC_DATATYPE) \
		$(SRC_DEBUG) \
		$(SRC_MEMORY) \
		$(SRC_PARSER) \
		$(SRC_INSTRUCT) \
		$(SRC_UTIL) \
		$(SRC_CHAMPION) \
		src/next_step.c \
		src/op.c \

TESTS =	../tests/corewar/copy_relative_bytes.c \
		../tests/corewar/jump_relative_bytes.c \
		../tests/corewar/write_relative_bytes.c \
		../tests/corewar/fetch_byte.c \

OBJ_TESTS = $(SRC:.c=.o) $(TESTS:.c=.o)

OBJ = $(SRC:.c=.o) src/main.o

all: build_lib
	${MAKE} -j build_all -C .

build_lib:
	$(LIB_MODULES) $(MAKE) -j -C ../lib/my/

build_all: $(OBJ)
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
