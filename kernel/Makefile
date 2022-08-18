CC = gcc
CFLAGS = -nostdlib -O2 -Wall -Wextra 

build:
	nasm src/syscall.asm -f elf64 -o syscall.o 
	nasm src/pagetable.asm -f elf64 -o pagetable.o
	cc  -c src/syscall_handler.c src/memory.c src/graphics.c  kernel.c $(CFLAGS) 
	ld syscall.o syscall_handler.o pagetable.o memory.o graphics.o kernel.o -T linker.ld -o kernel.elf
	rm syscall.o
	rm syscall_handler.o 
	rm graphics.o 
	rm kernel.o 
	rm pagetable.o 
	rm memory.o
	

