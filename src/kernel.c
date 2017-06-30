#include "tty.h"
#include <system.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


void* memcpy(char * dest, char * src, size_t length)
{
	for(size_t i = 0; i < length; i ++)
	{
		dest[i] = src[i];
	}
	return dest;
}


int kernel_main()
{
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

	/*
	vga_writeString("Testing window scrolling...");

	for(int i = 0; i < 15; i ++)
	{
		vga_putchar('\n');
		vga_writeDec(i);
		
	}
	//*/
	

	vga_writeString("\nsizeof(short) = ");
	vga_writeDec(sizeof(unsigned short));

	vga_writeString("\nsizeof(short) = ");
	vga_writeDec(sizeof(unsigned short));
	vga_writeString("\nsizeof(int) = ");
	vga_writeDec(sizeof(int));
	vga_writeString("\nsizeof(char) = ");
	vga_writeDec(sizeof(char));
	vga_writeString("\nsizeof(long) = ");
	vga_writeDec(sizeof(long));
//	halt(); // an assembly call to hlt, 
	gdt_install();

	while(true) {};

	return 0;
}
