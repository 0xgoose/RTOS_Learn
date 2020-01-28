#assemble boot.s file
as --32 boot.s -o boot.o

#compile kernel.c file
gcc -m32 -c main.c -o main.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T linker.ld main.o boot.o -o mytestos.bin -nostdlib

#run on qemu
qemu-system-x86_64 -kernel mytestos.bin
