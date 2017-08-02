/* A collection of functions for communicating directly with the terminal.
 * Moslty functions for the output of text.
 * 
 * */
#include "tty.h" 
#include "math.h" // abs()
#include "string.h" // strlen()

const size_t TABSIZE = 4;

uint16_t *terminal_buffer;
uint16_t terminal_x;
uint16_t terminal_y;
uint8_t  terminal_color;

const size_t VGA_WIDTH = 80;
const size_t VGA_HEIGHT = 25;
const size_t VGA_SPREAD = 80 * 25;


char* reverseString(char * str);


uint8_t vga_displayColor(enum vga_color foreground, enum vga_color background)
{
	return (uint8_t) foreground | background << 4;
}

uint16_t vga_entry(unsigned char text, uint8_t color)
{
	return (uint16_t) text | (uint16_t) color << 8;
}

// call once to initialize the tty terminal with a blank screen
void vga_init()
{
	vga_cls();	
	terminal_x = 0;
	terminal_y = 0;
}

// clear the screen
void vga_cls()
{
	size_t index = 0;
	terminal_color = vga_displayColor(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
	terminal_buffer = (uint16_t *) 0XB8000;
	for(size_t j = 0; j < VGA_HEIGHT; j ++)
	{
		for(size_t i = 0; i < VGA_WIDTH; i ++)
		{
			index = j * VGA_WIDTH + i;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
	terminal_buffer = (uint16_t *) 0XB8000;
}

// print a single character data to the screen at pos 
void vga_putEntryAt(const char data, const uint16_t pallet, const size_t x, const size_t y)
{
	terminal_buffer[VGA_WIDTH * y + x] = vga_entry(data, pallet);
}

void vga_splashLine(const size_t lineNumber)
{
	for(size_t i = 0; i < VGA_WIDTH; i ++)
	{
		vga_putEntryAt(' ', terminal_color, i, lineNumber);
	}
}


void vga_setCursorToTop()
{
	terminal_buffer = (uint16_t *) 0xB8000;
}

void vga_scroll(size_t lineCount)
{
	for(size_t i = 0; i < VGA_SPREAD; i ++)
	{
		terminal_buffer[i] = terminal_buffer[i+VGA_WIDTH * lineCount];
	}
//	memcpy((char*)terminal_buffer, (char*) (terminal_buffer + (VGA_WIDTH * lineCount)), (VGA_SPREAD - VGA_WIDTH * lineCount)/2);
//	vga_splashLine(VGA_HEIGHT - 1);
}

void vga_putchar(const char c)
{
	if(c == '\n')
	{
		terminal_x = 0;
		terminal_y ++;
	} // should implement other esc sequences like \t for tab
	else
	{
		vga_putEntryAt(c, terminal_color, terminal_x, terminal_y);
		terminal_x ++;
	}
	if(terminal_x >= VGA_WIDTH)
	{
		terminal_x = 0;
		terminal_y ++;
	}
	if(terminal_y >= VGA_HEIGHT)
	{
		vga_scroll(1);
		terminal_y --;
	}
}

void vga_writebuffer(const char* data, const int size)
{
	for(int i = size; i > 0; i ++)
	{
		vga_putchar(data[i]);
	}
}

void vga_setColor(uint16_t pallet)
{
	terminal_color = pallet;
}

void vga_write(const char* data, const size_t length)
{
	for(size_t i = 0; i < length; i ++)
	{
		vga_putchar(data[i]);
	}	
}

void vga_writeString(const char* str)
{
	vga_write(str, strlen(str));
}




void vga_writeDec(const int number)
{
	char text[12];
	itoa(number, text, 10);
	vga_writeString(text);
}


void vga_writeHex(const unsigned int number)
{
	vga_writeString("0x");
	char outchar[11];
	uitoa(number, outchar, 16);
	vga_writeString(outchar);	
}

void vga_writeBinary(const unsigned int number)
{
	vga_writeString("0b");
	char output[133];
	uitoa(number, output, 2);
	vga_writeString(output);
}

void vga_logEntry(char* label, char* string)
{
	vga_putchar('\n');
	uint8_t oldPalette = terminal_color;
	terminal_color = vga_displayColor(VGA_COLOR_WHITE, VGA_COLOR_LIGHT_BLUE);
	vga_writeString(label);
	vga_writeString(string);
	terminal_color = oldPalette;
	vga_putchar('\n');
}
/*
char* reverseString(char* str)
{
	char* text = str;
	size_t len = strlen(text);
	if(len > 0)
	{
		len --;
	
		size_t halfLen = len/2;
		for(size_t i = 0; i <= halfLen; i ++)
		{
			char temp = text[i];
			text[i] = text[len - i];
			text[len - i] = temp;
		}
		str = text;
	}
	return str;
}
*/
