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

# the beginning of the kernel.
_start:

mov $stack_top, %esp
call kernel_main

mov $stack_top, %esp
call kernel_main

	cli 
	hlt 
to_here:
	jmp to_here  


.macro PUSHALL
	pushl %eax
	pushl %ecx
	pushl %edx
	pushl %ebx
	pushl %esp
	pushl %ebp
	pushl %esi
	pushl %edi
.endm


.macro POPALL
	popl %edi
	popl %esi
	popl %ebp
	popl %esp
	popl %ebx
	popl %edx
	popl %ecx
	popl %eax
.endm



# use to halt the CPU in C code. Should be removed when debugging is done
.global halt
.type halt, @function
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
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %ss
	ljmp $0x08, $flush

flush:
	ret

# called to emplant my idt 
.globl idt_flush
.type idt_flush, @function

idt_flush:
	movl 4(%esp), %eax
	lidt (%eax)
	ret

/*
.globl inb
.type inb, @function
inb:
	movl 4(%esp), %eax
*/	


# the next two macros are used to shorten the process of declaring 256 isr functions below.
.macro isr_NE p
	.globl isr\p
	.type isr\p, @function
	isr\p:
		cli
		push $0
		push $\p
		jmp isr_common_stub
.endm


.macro isr_E p
	.globl isr\p
	.type isr\p, @function
	isr\p:
		cli
		push $(\p)
		jmp isr_common_stub
.endm


# Setting up all 256 isr functions. I probably could have been smart about this
# and tried nesting macros... Maybe next time around. 
isr_NE 0
isr_NE 1
isr_NE 2
isr_NE 3
isr_NE 4
isr_NE 5
isr_NE 6
isr_NE 7
isr_E 8
isr_NE 9
isr_E 10
isr_E 11
isr_E 12
isr_E 13
isr_E 14
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
isr_NE 33
isr_NE 34
isr_NE 35
isr_NE 36
isr_NE 37
isr_NE 38
isr_NE 39
isr_NE 40
isr_NE 41
isr_NE 42
isr_NE 43
isr_NE 44
isr_NE 45
isr_NE 46
isr_NE 47
isr_NE 48
isr_NE 49
isr_NE 50
isr_NE 51
isr_NE 52
isr_NE 53
isr_NE 54
isr_NE 55
isr_NE 56
isr_NE 57
isr_NE 58
isr_NE 59
isr_NE 60
isr_NE 61
isr_NE 62
isr_NE 63
isr_NE 64
isr_NE 65
isr_NE 66
isr_NE 67
isr_NE 68
isr_NE 69
isr_NE 70
isr_NE 71
isr_NE 72
isr_NE 73
isr_NE 74
isr_NE 75
isr_NE 76
isr_NE 77
isr_NE 78
isr_NE 79
isr_NE 80
isr_NE 81
isr_NE 82
isr_NE 83
isr_NE 84
isr_NE 85
isr_NE 86
isr_NE 87
isr_NE 88
isr_NE 89
isr_NE 90
isr_NE 91
isr_NE 92
isr_NE 93
isr_NE 94
isr_NE 95
isr_NE 96
isr_NE 97
isr_NE 98
isr_NE 99
isr_NE 100
isr_NE 101
isr_NE 102
isr_NE 103
isr_NE 104
isr_NE 105
isr_NE 106
isr_NE 107
isr_NE 108
isr_NE 109
isr_NE 110
isr_NE 111
isr_NE 112
isr_NE 113
isr_NE 114
isr_NE 115
isr_NE 116
isr_NE 117
isr_NE 118
isr_NE 119
isr_NE 120
isr_NE 121
isr_NE 122
isr_NE 123
isr_NE 124
isr_NE 125
isr_NE 126
isr_NE 127
isr_NE 128
isr_NE 129
isr_NE 130
isr_NE 131
isr_NE 132
isr_NE 133
isr_NE 134
isr_NE 135
isr_NE 136
isr_NE 137
isr_NE 138
isr_NE 139
isr_NE 140
isr_NE 141
isr_NE 142
isr_NE 143
isr_NE 144
isr_NE 145
isr_NE 146
isr_NE 147
isr_NE 148
isr_NE 149
isr_NE 150
isr_NE 151
isr_NE 152
isr_NE 153
isr_NE 154
isr_NE 155
isr_NE 156
isr_NE 157
isr_NE 158
isr_NE 159
isr_NE 160
isr_NE 161
isr_NE 162
isr_NE 163
isr_NE 164
isr_NE 165
isr_NE 166
isr_NE 167
isr_NE 168
isr_NE 169
isr_NE 170
isr_NE 171
isr_NE 172
isr_NE 173
isr_NE 174
isr_NE 175
isr_NE 176
isr_NE 177
isr_NE 178
isr_NE 179
isr_NE 180
isr_NE 181
isr_NE 182
isr_NE 183
isr_NE 184
isr_NE 185
isr_NE 186
isr_NE 187
isr_NE 188
isr_NE 189
isr_NE 190
isr_NE 191
isr_NE 192
isr_NE 193
isr_NE 194
isr_NE 195
isr_NE 196
isr_NE 197
isr_NE 198
isr_NE 199
isr_NE 200
isr_NE 201
isr_NE 202
isr_NE 203
isr_NE 204
isr_NE 205
isr_NE 206
isr_NE 207
isr_NE 208
isr_NE 209
isr_NE 210
isr_NE 211
isr_NE 212
isr_NE 213
isr_NE 214
isr_NE 215
isr_NE 216
isr_NE 217
isr_NE 218
isr_NE 219
isr_NE 220
isr_NE 221
isr_NE 222
isr_NE 223
isr_NE 224
isr_NE 225
isr_NE 226
isr_NE 227
isr_NE 228
isr_NE 229
isr_NE 230
isr_NE 231
isr_NE 232
isr_NE 233
isr_NE 234
isr_NE 235
isr_NE 236
isr_NE 237
isr_NE 238
isr_NE 239
isr_NE 240
isr_NE 241
isr_NE 242
isr_NE 243
isr_NE 244
isr_NE 245
isr_NE 246
isr_NE 247
isr_NE 248
isr_NE 249
isr_NE 250
isr_NE 251
isr_NE 252
isr_NE 253
isr_NE 254
isr_NE 255

# Defined in src/idt.c
.extern isr_handler

isr_common_stub:
	PUSHALL

	movw %ds, %ax
	pushl %eax

	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs
	
call isr_handler

	popl %eax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %gs

	POPALL
	add $8, %esp
	sti
	iret
	ret

.size _start, . - _start 

