/* A collection of functions for communicating directly with the terminal.
 * Moslty functions for the output of text.
 * 
 * */

terminal_cursor = 0xB8000;


// call once to initialize the tty terminal
void vga_init()
{
	
}

// clear the screen
void vga_cls();

// print a single character data to the screen at pos 
void vga_putchar(const char data, const int pos);

unsigned int vga_getCursorPos();

void vga_setCursorToTop();

void vga_writebuffer(const char* data, const int size);


void vga_write(const char* string);


void vga_writeDec(const int number);


void vga_writeHex(const int number);






