CFLAGS=-ffreestanding -O2 -std=gnu99 -Wall -Wextra -Iinclude
CFILEFLAGS=-c
CLINKERFLAGS=-ffreestanding -O2 -nostdlib
STABLE_FOLDER = stable_src

CC=i686-elf-gcc
AS=i686-elf-as

all: build iso clean run

build:
	$(AS) src/boot.s -o boot.o
	$(CC) $(CFILEFLAGS) src/string.c -o string.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/math.c -o math.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/tty.c -o tty.o $(CFLAGS)
	$(CC) $(CFILEFLAGS) src/kernel.c -o kernel.o $(CFLAGS)
	./_ echo this should not run, Use it to skip over commands in Makefile.
	$(CC) -T linker.ld -o myos.bin $(CLINKERFLAGS) boot.o string.o math.o tty.o kernel.o -lgcc

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
