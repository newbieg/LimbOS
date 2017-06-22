/* A collection of functions for communicating directly with the terminal.
 * Moslty functions for the output of text.
 * 
 * */

#include <stddef.h>


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






