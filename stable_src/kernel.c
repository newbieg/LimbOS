#include "tty.h"
#include <string.h>

#include <system.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>



int kernel_main()
{

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

	vga_logEntry("Log Entry:", "Happy new OS", LOG_NEUTRAL);

	vga_writeString("Testing window scrolling...");

	/* // This is very slow. I tried commenting out the lines that
		// actually output to screen and the rest of the algorithm
		// took less than a second (though there was a slight pause).
		// I need to figure out a way to speed up screen output. 
		// Currently thinking of ways to output entire pages at a time
		// if it's detected that the screen is very busy.
		// Might also figure out how to write memcpy in assembly. 
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

	char bub[30];
	vga_writeString("\nUsing my itoa function: ");
	vga_writeString(itoa(0x3A, bub, 16));
	vga_writeString("\nUsing my itoa function: ");
	vga_writeString(itoa(0x34, bub, 16));
	vga_putchar('\n');
	vga_writeString(itoa(34, bub, 2));

	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.", LOG_GOOD);
	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.", LOG_BAD);
	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.This is going to be an extra long terminal log entry just so that I can try to get the background to match even if it spans multiple lines.", LOG_UGLY);

	vga_logEntry("Warning:", "No Keyboard found. Press Enter to Continue.", LOG_WARN);
	

	return 0;
}
