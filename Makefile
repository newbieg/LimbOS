
all: build iso run

build:
	make -C src all

iso:
	mkdir -p isodir/boot/grub
	cp splash.png isodir/boot/grub
	cp src/myos isodir/boot/myos_nightly
	cp grub.cfg isodir/boot/grub/
	grub2-mkrescue -o myos.iso isodir

run:
	qemu-system-x86_64 -cdrom myos.iso -serial stdio -m 1024M

clean:
	-rm *.o *.h.gch *.bin *.iso
	make -C src clean
	-rm -rf isodir

