/* A collection of functions for communicating directly with the terminal.
 * Moslty functions for the output of text.
 * 
 * */
#include "tty.h"
#include "string.h"

const size_t TABSIZE = 4;

uint16_t *terminal_cursor;
uint16_t *terminal_x;
uint16_t *terminal_y;
uint8_t  *terminal_color;

enum vga_color
{
	VGA_COLOR_BLACK, 
	VGA_COLOR_BLUE,
	VGA_COLOR_GREEN,
	VGA_COLOR_CYAN,
	VGA_COLOR_RED,
	VGA_COLOR_MAGENTA,
	VGA_COLOR_BROWN,
	VGA_COLOR_LIGHT_GREY,
	VGA_COLOR_DARK_GREY,
	VGA_COLOR_LIGHT_BLUE,
	VGA_COLOR_LIGHT_GREEN,
	VGA_COLOR_LIGHT_CYAN,
	VGA_COLOR_LIGHT_RED,
	VGA_COLOR_LIGHT_MAGENTA,
	VGA_COLOR_LIGHT_BROWN,
	VGA_COLOR_WHITE,

};


uint8_t vga_displayColor(enum vga_color foreground, enum vga_color background)
{
	return foreground | background << 4;
}

uint16_t vga_entry(unsigned char text, uint8_t color)
{
	return (uint16_t) text | (uint16_t) color << 8;
}




// call once to initialize the tty terminal with a blank screen
void vga_init()
{
	vga_cls();	
}

// clear the screen
void vga_cls()
{
	terminal_color = vga_displayColor(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
	terminal_buffer = (uint16_t *) 0XB8000;
	for(int i = 0, int j = 0; j < VGA_HEIGHT; i ++)
	{
		if(i > VGA_WIDTH)
		{
			j ++;
			i = 0;
		}
		const size_t index = y * VGA_HEIGHT + x;
		terminal_buffer[index] = vga_entry(' ', terminal_color);
	}
}

// print a single character data to the screen at pos 
void vga_putEntryAt(const char data, const uint16_t pallet, const size_t x, const size_t y)
{
	terminal_buffer[VGA_WIDTH * y + x] = vga_entry(data, pallet);
}

unsigned int vga_getCursorPos()
{
	return terminal_buffer;
}

void vga_setCursorToTop()
{
	terminal_buffer = 0xB8000;
}

void vga_scroll(int lineCount)
{
	for(size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i ++)
	{
		terminal_buffer[i] = terminal_buffer[i+VGA_WIDTH * lineCount];
	}
}

void vga_putchar(char c)
{
	if(c == '\n')
	{
		terminal_x = 0;
		terminal_y ++;
	} // should implement other esc sequences like \t for tab
	else if(c == '\t')
	{
		for(size_t i = 0; i < TABSIZE; i ++)
		{
			terminal_putEntryAt(' ', terminal_color, terminal_x + i, termninal_y);
		}
		terminal_x += TABSIZE;
	}
	else
	{
		terminal_putEntryAt(c, terminal_color, terminal_x, terminal_y);
	}
	if(terminal_x >= VGA_WIDTH)
	{
		terminal_x = 0;
		terminal_y ++;
	}
	if(terminal_y >= VGA_HEIGHT)
	{
		terminal_scroll(1);
		terminal_y --;
	}
}

void vga_writebuffer(const char* data, const int size)
{
	for(int i = size; i > 0; i ++)
	{
		vga_putChar(data[i]);
	}
}

void vga_setColor(uint16_t pallet)
{
	terminal_color = pallet;
}


void vga_write(const char* data, size_t length)
{
	
}


void vga_writeDec(const int number);


void vga_writeHex(const int number);






