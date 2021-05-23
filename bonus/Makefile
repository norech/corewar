CC = emcc

SRC_LIB     = 	$(wildcard ../lib/my/src/**/*.c) \
				$(wildcard ../lib/my/src/*.c)

SRC_ASM     = 	../corewar/src/op.c \
				$(wildcard ../asm/src/**/**/*.c) \
				$(wildcard ../asm/src/**/*.c) \
				$(wildcard ../asm/src/*.c)

SRC_COREWAR = 	$(wildcard ../corewar/src/**/*.c) \
				$(wildcard ../corewar/src/*.c)

ASM_EXPORTED = 		[ \
						"_compile_string", \
						"_write" \
					]

COREWAR_EXPORTED = 	[\
						"_alloc_program_memory", \
						"_free_program_memory", \
						"_create_champion_from_bytes", \
						"_alloc_champion", \
						"_free_champion", \
						"_move_to_champion_pos", \
						"_parse_bytecode", \
						"_debug_memory", \
						"_next_step" \
					]

CFLAGS = -DSOFT_TYPES -I../include -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -s MODULARIZE=1

CFLAGS_ASM = $(CFLAGS) -s EXPORTED_FUNCTIONS='$(ASM_EXPORTED)' -s EXPORT_NAME='createCompiler'
CFLAGS_COREWAR = $(CFLAGS) --source-map-base /build/ --emit-symbol-map -g -gsource-map -s EXPORTED_FUNCTIONS='$(COREWAR_EXPORTED)' -s ASYNCIFY -s EXPORT_NAME='createVM'

build_wasm:
	$(CC) $(CFLAGS_ASM) $(SRC_ASM) $(SRC_LIB) -o public/build/asm.js
	$(CC) $(CFLAGS_COREWAR) $(SRC_COREWAR) $(SRC_LIB) -o public/build/corewar.js

build_svelte:
	npm run build

build_all: build_wasm build_svelte