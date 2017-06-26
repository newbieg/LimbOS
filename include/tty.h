/* A collection of functions for communicating directly with the terminal.
 * Moslty functions for the output of text.
 * 
 * */

#include <stddef.h>

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


// call once to initialize the tty terminal
void vga_init();

// clear the screen
void vga_cls();

// print a single character data to the screen at pos 
void vga_putchar(const char data);

unsigned int vga_getCursorPos();

void vga_setCursorToTop();

void vga_writeBuffer(const char* data, const int size);

void vga_writeWarning(const char* string);
void vga_writeInfo(const char* string);

void vga_write(const char* data, const size_t size);
void vga_writeString(const char* string);

void vga_scroll(size_t lines);

void vga_writeDec(const int number);


void vga_writeHex(const int number);


void vga_logEntry(char* label, char * string);




