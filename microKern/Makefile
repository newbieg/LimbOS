CFLAGS=-ffreestanding -O2 -std=gnu99 -Wall -Wextra -Iinclude
CFILEFLAGS=-c -O3
CLINKERFLAGS=-ffreestanding -O2 -nostdlib
STABLE_FOLDER = stable_src

CC=i686-elf-gcc
AS=i686-elf-as

all: build iso run clean

build:
	$(AS) src/boot.s -o boot.o
	$(CC) $(CFILEFLAGS) src/string.c -o string.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/math.c -o math.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/tty.c -o tty.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/io.c -o io.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/kbd.c -o kbd.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/regs.c -o regs.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/kernel.c -o kernel.o $(CFLAGS)
	$(CC) -T linker.ld -o myos.bin $(CLINKERFLAGS) boot.o string.o math.o tty.o io.o kbd.o regs.o kernel.o -lgcc

build_stable:
	$(AS) $(STABLE_FOLDER)/boot.s -o boot.o
	$(CC) $(CFILEFLAGS) $(STABLE_FOLDER)/string.c -o string.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) $(STABLE_FOLDER)/math.c -o math.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) $(STABLE_FOLDER)/tty.c -o tty.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) $(STABLE_FOLDER)/kernel.c -o kernel.o $(CFLAGS)
	$(CC) -T linker.ld -o myos.bin $(CLINKERFLAGS) boot.o string.o math.o tty.o kernel.o -lgcc

stable: build_stable
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

nasm:
	nasm -f elf32 smallest.s
	ld -T link.ld -melf_i386 smallest.o -o myos.bin
	cp myos.bin isodir/boot/
	grub2-mkrescue -o myos.iso isodir
	bochs -f bock.txt -q
	



