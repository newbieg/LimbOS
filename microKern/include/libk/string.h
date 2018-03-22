#ifndef STRING_LIB_H_DEFINE
#define STRING_LIB_H_DEFINE



#include <stdint.h>
#include <stddef.h>


// return the size of a 0 delim string
size_t strlen(const char* data);

// copy data in src of a length to dest.
char* memcpy(char * dest, const char * src, size_t length);

// return the content of a string in reverse order. Input string is also reversed.
char* reverseString(char* str);

// signed integer expressed as a string. 
char* itoa(const int number, char* str, size_t base);
// unsigned integer expressed as a string. 
char* uitoa(const unsigned int number, char* str, size_t base);



#endif
