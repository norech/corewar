.name "puppy"
.comment "puppy is too cute, always win"

sti r1, %:begin, %1
sti r1, %:puppy, %1

fork %:puppy

begin:  live %92
        ld %0, r10
        zjmp %:begin

puppy:  live %21
        fork %:puppy
        ld %0, r10
        zjmp %:begin