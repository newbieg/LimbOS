#ifndef STRING_LIB_H_DEFINE
#define STRING_LIB_H_DEFINE



#include <stdint.h>
#include <stddef.h>


size_t strlen(const char* data);

char* memcpy(char * dest, const char * src, size_t length);

char* reverseString(char*);

char* itoa(const int number, char* str, size_t base);
char* uitoa(const unsigned int number, char* str, size_t base);



#endif
