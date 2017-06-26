#include <string.h>



// not the safest way to get the length of a string
// since there's the possibility that the string is not
// zero terminated. 
size_t strlen(const char * data)
{
	size_t i = 0;
	for(i = 0; data[i]; i ++)
	{}
	return i;
}



