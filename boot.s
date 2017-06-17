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
.type _start, @function

; the entry point for our kernel after the grub multiboot;
_start:

mov $stack_top, %esp
call kernel_main

mov $stack_top, %esp
call kernel_main

	cli ; clear interupts
	hlt ; tell CPU to halt, uses less power... Will not resume unless interupts occur
to_here:
	jmp to_here ; this is our infinite loop should interupts be turned back on. 

.size _start, . - _start 
