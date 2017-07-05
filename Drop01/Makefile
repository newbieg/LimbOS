CFLAGS=-ffreestanding -O2 -std=gnu99 -Wall -Wextra -Iinclude
CFILEFLAGS=-c
CLINKERFLAGS=-ffreestanding -O2 -nostdlib

CC=i686-elf-gcc
AS=i686-elf-as

all: build iso clean run

build:
	$(AS) src/boot.s -o boot.o
	$(CC) $(CFILEFLAGS) src/string.c -o string.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/math.c -o math.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/tty.c -o tty.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/gdt.c -o gdt.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/idt.c -o idt.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/timer.c -o timer.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/kernel.c -o kernel.o $(CFLAGS)
	$(CC) -T linker.ld -o myos.bin $(CLINKERFLAGS) boot.o string.o math.o tty.o gdt.o idt.o timer.o kernel.o -lgcc

stable: build
	cp myos.bin isodir/boot/myos_stable.bin
	cp grub.cfg isodir/boot/grub/

iso:
	cp myos.bin isodir/boot/myos_nightly.bin
	cp grub.cfg isodir/boot/grub/
	grub2-mkrescue -o myos.iso isodir

run:
	qemu-system-i386 -cdrom myos.iso

clean:
	-rm *.o *.h.gch
