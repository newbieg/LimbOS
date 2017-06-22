CFLAGS=-ffreestanding -O2 -std=gnu99 -Wall -Wextra
CFILEFLAGS=-c
CLINKERFLAGS=-ffreestanding -O2 -nostdlib

CC=i686-elf-gcc
AS=i686-elf-as

all:
	$(AS) boot.s -o boot.o
	$(CC) $(CFILEFLAGS) string.c -o string.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) math.c -o math.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) tty.c -o tty.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) kernel.c -o kernel.o $(CFLAGS)
	$(CC) -T linker.ld -o myos.bin $(CLINKERFLAGS) boot.o string.o math.o tty.o kernel.o -lgcc
	cp myos.bin isodir/boot
	cp grub.cfg isodir/boot/grub/
	grub2-mkrescue -o myos.iso isodir
	qemu-system-i386 -cdrom myos.iso
