// Multiboot2 header
.SET HEADER_LENGTH, header_end - header_start
.SET CHECKSUM,	-(0xe85250d6 + HEADER_LENGTH)
.section .multiboot
header_start:
	.long 0xe85250d6 #mutliboot2 magic number
	.long 0
	.long HEADER_LENGTH
	.long CHECKSUM
	
	.short 0
	.short 0
	.long 8
header_end:

.code32
.section .bss
stack_bottom:
	.skip 0x4000 
stack_top:

.data
.align 0x1000
pml4:
	.skip 0x1000
low_pdpt:
	.skip 0x1000
high_pdpt:
	.skip 0x1000
low_pd:
	.skip 0x1000
high_pd:
	.skip 0x1000

gdt_start:
gdt_null:
	.long 0
	.long 0
	.long 0
	.long 0
gdt_code:
	.long 0
	.long 0
	.short 0
	.short 0b10011010
	.short 0b00100000
	.short 0
gdt_data:
	.long 0
	.long 0
	.short 0
	.short 0b10010010
	.short 0
	.short 0
gdt_end:
	
gdt_ptr:
	.short gdt_start - gdt_end;
	.long gdt_start


.section .text
.global _start
.type _start, @function

_start:
	cli
	cld
	mov $stack_top, %esp

	movl $low_pdpt, %eax
	movl %eax, pml4 +
	

	call kernel_main

	mov $stack_top, %esp
	sti
	movl $_kernel_physical_end, %esi
	
	call kernel_main

to_here:
	hlt 
	jmp to_here  


# void halt();
# use to halt the CPU in C code. Should be removed when debugging is done
.global halt
.type halt, @function
halt:
	hlt
	ret


// A major function for IO operations. 
// probably there is a better place than
// here to put it, but for now I only keep
// one ASM file...
// void outb(unsigned short port_Number, unsigned char output_Data)
.global outb
.type outb, @function
outb:
	mov 8(%esp), %al
	mov 4(%esp), %dx
	out %al, %dx
	ret


// move the address into dx
// then read a byte from that address.
.global inb
.type inb, @function
inb:
	mov 4(%esp), %dx
	in %dx, %al
	ret



.global io_disableInterrupts
.type io_disableInterrupts, @function
io_disableInterrupts:
	cli
	ret

.global io_enableInterrupts
.type io_enableInterrupts, @function
io_enableInterrupts:
	sti
	ret


// declared in /src/system.h
//int* pushRegs(int[10] list) 
// returns pointer to int array containing register vals
.global pushRegs
.type pushRegs, @function
pushRegs:
	push %ebp ; //save base pointer
	mov %ebx, %edi

	mov %ebx, (%edi)
	mov %eax, 4(%edi)
	mov %ecx, 8(%edi)
	mov %edx, 12(%edi)
	mov %edi, 16(%edi)
	mov %esi, 20(%edi)
	mov %esp, 24(%edi)
	mov %ebp, 28(%edi)

	pop %ebp
	ret

.global getCPUID
.type getCPUID, @function
getCPUID:
	xor %eax, %eax
	cpuid


.global getBootSize
.type getBootSize, @function
	mov (. - _start), %eax

.size _start, . - _start 

