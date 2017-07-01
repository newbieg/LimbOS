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
	cld
	movl 4(%esp), %eax
	lgdt (%eax)
	movw $0x10, %ax

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

.macro isr_NE p
	.globl isr\p
	isr\p:
		cli
		push 0
		push \p
		jmp isr_common_stub
.endm


.macro isr_E p
	.globl isr\p
	isr\p:
		cli
		push \p
		jmp isr_common_stub
.endm


isr_NE 0
isr_NE 1
isr_NE 2
isr_NE 3
isr_NE 4
isr_NE 5
isr_NE 6
isr_NE 7
isr_NE 8
isr_NE 9
isr_NE 10
isr_NE 11
isr_NE 12
isr_NE 13
isr_NE 14
isr_NE 15
isr_NE 16
isr_NE 17
isr_NE 18
isr_NE 19
isr_NE 20
isr_NE 21
isr_NE 22
isr_NE 23
isr_NE 24
isr_NE 25
isr_NE 26
isr_NE 27
isr_NE 28
isr_NE 29
isr_NE 30
isr_NE 31
isr_NE 32


.extern isr_handler

isr_common_stub:

	movw %ax, %ds
	push %eax

	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	
call isr_handler
	pop %eax

	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs

	add 8, %eax
	sti
	ret

.size _start, . - _start 

