# Corewar

## What's Corewar?

Corewar is a programming game where the goal is to make
the champion that will be the last to stay alive.

These champions are programs made in a assembly-like
language called redcode.

These champions will be compiled to bytecode and run inside a VM.

Several champions programs are written and executed in a shared memory
that can be readed and rewritten at runtime by any champions' instructions.
It make it possible to corrupt the champions' programs and make them lose.

## What is this repo?

This repo is an implementation of the ASM compiler and the Corewar VM, as part
of an Epitech project.

This project is intended to run on an x86_64 Linux.
To build the project, you need `gcc` and `make`.
```bash
make
```

## The compiler

This repo implementations use a three-step ASM compilation to convert a source file to bytecode.

```
./asm/asm [source code.s]
```

### The parser

First, the source code is parsed to an abstract syntax tree containing both
the instructions and the labels.

### The analyzer

After that, this tree is analyzed to check eventual semantic errors (e.g. invalid arguments).
Once the tree is validated, the instructions' bytecode size will be precalculated.

Each instruction arguments will be resolved to a numeric value corresponding to a relative
offset in bytes (yes, that's why we needed to precalculate bytecode sizes).

### The generator

Once these steps are done, the generator will take our tree and transform it to a bytecode
that can be understood by a Redcode-compatible VM.

## The VM

```bash
./corewar/corewar -h
```

The virtual machine should handle memory accesses and registries.
It should also be able to schedule and execute the instructions of each champions from
the program bytecode,
since each instructions can take a certain amount of cycles to run, that can be different
depending on the instruction.

The virtual machine is also responsible of checking which champion is alive, and should
stop once a winner was found.

Each champion can have several instances, that can be "forked" using the `fork` instruction.

## Additional features

### Debugger

A champions step-by-step debugger was also provided, usable by adding the `-debug` flag.

It can:
- Show a colored memory dump
- Show which memory bytes has been modified since last step, and whom modified it.
- Show the values stored in the registries on each step
- Disassemble the instructions at runtime on each step
- Detect when a registry passed in argument is invalid

### Compiler using WASM

An experimental online compiler has also been provided, it is able to create a champion compiled
file from the source code that the user provides.

To be built, it requires the emscriptem sdk as additional dependency.

It can be built and started using the following commands:
```bash
cd bonus
make
npm run dev     # npm run build
```
