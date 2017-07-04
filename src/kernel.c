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
	//* // Testing for correct decimal outputs
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

	asm volatile ("int $0x03");
	//asm volatile ("int $0x06");

	vga_writeString("\nsizeof(unsigned short) = ");
	vga_writeDec(sizeof(unsigned short));
	vga_writeString("\nsizeof(unsigned int) = ");
	vga_writeDec(sizeof(unsigned int));
	vga_writeString("\nsizeof(unsigned char) = ");
	vga_writeDec(sizeof(unsigned char));
	vga_writeString("\nsizeof(unsigned long) = ");
	vga_writeDec(sizeof(unsigned long));


//	halt(); // an assembly call to hlt, 

	return 0;
}
