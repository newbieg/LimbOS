/* A list of key functions that the kernel will need to use in order to
 * communicate with the system.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// extern void halt();
// An Assembly call to hlt, defined in boot.s
// Currently only used for debugging purposes.
extern void halt();

// void* memcpy(char* dest, char* src, size_t length);
// defined in kernel.c
// copies length amount of chars from src to dest.
// Return: dest
void* memcpy(char * dest, char * src, size_t length);


// void* memset(char* dest, char value, size_t length);
// defined in kernel.c
// loads length amount of value into dest.
// Return: dest
void* memset(char* dest, const char value, size_t length);


// GDT

// Set up a GDT entry.
void gdt_set_gate(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran);

// Called once to set up the system GDT.
void gdt_install();

void writeGDTSize();


