#ifndef SYSTEM_FUNCTSLIB_H_DEFINE
#define SYSTEM_FUNCTSLIB_H_DEFINE


/* A list of key functions that the kernel will need to use in order to
 * communicate with the system. The source files will be found in the 
 * src folder. The src folder should be used solely for kernel-
 * permision code. (System Calls).
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// extern void halt();
// An Assembly call to hlt, defined in boot.s
// Currently only used for debugging purposes.
extern void halt();
void reboot();
extern int pushRegs(int list[]);
void printRegs();



// void* memcpy(char* dest, char* src, size_t length);
// defined in kernel.c
// copies length amount of chars from src to dest.
// Return: dest
//void* memcpy(char * dest, char * src, size_t length);


// void* memset(char* dest, char value, size_t length);
// defined in kernel.c
// loads length amount of value into dest.
// Return: dest
void* memset(char* dest, const char value, size_t length);


/* contemplating moving to gdt.h
// GDT

// Set up a GDT entry.
void gdt_set_gate(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran);

// Called once to set up the system GDT.
void gdt_install();

void writeGDTSize();
*/





#endif
