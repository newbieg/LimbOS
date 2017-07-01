.set ALIGN,	1<<0
.set MEMINFO,	1<<1
.set FLAGS,	ALIGN | MEMINFO
.set MAGIC,	0x1BADB002
.set CHECKSUM,	-(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .text
.global _start
#.type _start, @function

_start:

mov $stack_top, %esp
call kernel_main

mov $stack_top, %esp
call kernel_main

	cli 
	hlt 
to_here:
	jmp to_here  


.global halt
halt:
	hlt
	ret

# GDT function flush will clear the old segment registers
# from whatever Grub Multiboot has provided.
# and then do a far-jump. Right now this is magic to me, 
# brought to you by Bran's Tutorials though I translated them 
# from NASM to GNU-as.

.globl gdt_flush
.type gdt_flush, @function

gdt_flush:
	cli
	movl 4(%esp), %eax
	lgdt (%eax)
	movw $0x10, %ax

	push 4(%esp) /* following 3 lines are for testing */
call writeGDTSize
/* The 'issue' starts here */
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss
	ljmp $0x08, $flush

flush:
	ret

.globl idt_flush
idt_flush:
	movl 4(%esp), %eax
	lidt (%eax)
	ret

.size _start, . - _start 

