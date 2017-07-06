#include "tty.h"
#include <system.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <gdt.h>
#include <idt.h>
#include <timer.h>


void* memcpy(char * dest, char * src, size_t length)
{
	for(size_t i = 0; i < length; i ++)
	{
		dest[i] = src[i];
	}
	return dest;
}

void* memset(char* dest, const char val, size_t length)
{
	for(size_t i = 0; i < length; i ++)
	{
		dest[i] = val;
	}
	return dest;
}


int kernel_main()
{

	gdt_install();
	idt_install();
	init_timer(50);
	vga_init();
	
	vga_writeString("Hello World");
	vga_putchar('\n');
	/// Testing for correct decimal outputs
	vga_writeDec(-12);
	vga_writeDec(-123);
	vga_writeDec(-1234);
	vga_writeDec(-12345);
	vga_writeDec(-1234567890);
	vga_putchar('\n');

	vga_logEntry("Log Entry:", "Happy new OS");

	vga_writeString("Testing window scrolling...");

	for(int i = 0; i < 25; i ++)
	{
		vga_putchar('\n');
		vga_writeDec(i);
		
	}

//	asm volatile ("int $0x00");
//	asm volatile ("int $0x01");
//	asm volatile ("int $0x02");
//	asm volatile ("int $0x03");
//	asm volatile ("int $0x04");
//	asm volatile ("int $0x05");
//	asm volatile ("int $0x06");
//	asm volatile ("int $0x07");
//	asm volatile ("int $0x08");
//	asm volatile ("int $0x09");

	vga_writeString("\nsizeof(unsigned short) = ");
	vga_writeDec(sizeof(unsigned short));
	vga_writeString("\nsizeof(unsigned int) = ");
	vga_writeDec(sizeof(unsigned int));
	vga_writeString("\nsizeof(unsigned char) = ");
	vga_writeDec(sizeof(unsigned char));
	vga_writeString("\nsizeof(unsigned long) = ");
	vga_writeDec(sizeof(unsigned long));
	vga_writeString("\n\nDEVELOPMENT HALTED:\nI'm dropping development in this branch.\n\
I ran into issues with my gdt/idt/irq and \n\
am having trouble actually ID'ing what the\n\
problem is. I'll keep this branch around \n\
as a resource.");


//halt(); // an assembly call to hlt, 

while(true){} 

	return 0;
}