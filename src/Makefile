CC=x86_64-elf-gcc
SHARED_FLAGS= -fno-builtin -ffreestanding -O2 -g -nostdlib -C  -Wall -Wextra -I. -I../include -L../include/libk -MMD -mno-red-zone -mcmodel=kernel -fno-pie


CFLAGS = $(SHARED_FLAGS)
ASFLAGS = $(SHARED_FLAGS) -Wa,--divide

OBJS := boot.o
OBJS += kernel.o
OBJS += string.o
OBJS += math.o
OBJS += tty.o
OBJS += io.o
OBJS += kbd.o
OBJS += regs.o

DFILES = $(patsubst %.o, %.d, $(OBJS))



all: build 

build: $(OBJS) linker.ld Makefile
	$(CC) -z max-page-size=0x1000 $(CFLAGS) -no-pie -Wl,--build-id=none -T linker.ld -o myos $(OBJS)

clean:
	-rm *.o *.d *.h.gch *.bin *.iso

$(OBJS): Makefile
-include $(DFILES)
