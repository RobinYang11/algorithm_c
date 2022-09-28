

## build 1.hello.asm
nasm -f elf 1.hello.asm

ld -m elf_i836 -s -o hello 1.hello.o
