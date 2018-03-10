global loader
MAGIC_NUM equ 0xBADB002
FLAGS equ 0x0
CHECKSUM equ -(MAGIC_NUM + FLAGS)

section .multiboot
align 4
	dd MAGIC_NUM
	dd FLAGS
	dd CHECKSUM

section .text
align 4

loader:
	mov eax, 0xCAFEBABE

.loop:
	jmp .loop
	
