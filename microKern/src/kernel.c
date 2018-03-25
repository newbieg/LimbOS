#include <tty.h>
#include <libk/string.h>
#include <io.h>

#include <system.h>
#include <kbd_map.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void reboot()
{
	unsigned char good = 0x02;
	while((good & 0x02) != 0)
	{
		good = inb(0x02);
	}
	outb(0x64, 0xFE);
	halt();
}


int kernel_main()
{

	vga_init();
	
	vga_writeString("Hello World");
	vga_putchar('\n');
	printRegs();
	vga_putchar('\n');
	/// Testing for correct decimal outputs
	vga_writeDec(-12345);
	vga_logEntry("Log Entry:", "Happy new OS", LOG_NEUTRAL);
	vga_writeString("Testing window scrolling...");

	/*
	for(unsigned int i = 0; i < 5000; i ++)
	{
		vga_putchar('\n');
		vga_writeBinary(i);
	}
*/

	vga_putchar('\n');
	vga_writeHex(0x60789);
	vga_putchar('\n');
	vga_writeBinary(0x60789);
//	vga_setBackgroundColor(VGA_COLOR_GREEN);
//	vga_setTextColor(VGA_COLOR_LIGHT_CYAN);
	vga_putchar('\n');
	vga_writeBinary(0x30);
	vga_putchar('\n');
	vga_writeBinary(0x30);
	vga_writeString("\n10 & 11 = ");
	vga_writeDec((10 & 11));
	vga_writeString("\n11 & 12 = ");
	vga_writeDec((11 & 12));
	vga_writeString("\n10 | 11 = ");
	vga_writeDec((10 | 11));
	vga_writeString("\n binary 100 = ");
	vga_writeBinary(0b100);

	char bub[34];
	vga_writeString("\nUsing my base-changing itoa function: ");
	vga_writeString(itoa(0x3A, bub, 16));
	vga_writeString(" = ");
	vga_writeString(itoa(0x34, bub, 10));
	vga_writeString(" = ");
	vga_writeString(itoa(0x34, bub, 2));
	vga_writeString("\n");

	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.", LOG_GOOD);
	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.", LOG_BAD);
	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.This is going to be an extra long terminal log entry just so that I can try to get the background to match even if it spans multiple lines.", LOG_UGLY);

	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.", LOG_WARN);



	vga_putchar('\n');
	printRegs();
//	io_disableInterupts();
//	io_enableInterupts();

//	io_wait();

	while(true)
	{
		char k = getKey();
		vga_putchar(k);

	}

	halt();
	return 0;
}
