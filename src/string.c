#include <libk/string.h>
#include <libk/math.h>

char* itoa(const int number, char* str, size_t base)
{
	if(number == 0 || number == (int) 0b10000000000000000000000000000000)
        {
		str[0] = '0';
		str[1] = '\0';
        }
	else
	{
		int tempNum = number;
		size_t count = 0;
        	if(tempNum < 0)
        	{
        	        str[0] = '-';
        	        count ++;
        	}
        	int start = count;
        	tempNum = abs(tempNum);
        	while(tempNum > 0)
        	{
        	        int tmp = tempNum % base;
			if(tmp <= 9)
			{
        	        	str[count] = '0' + tmp;
			}
			else
			{
        	        	str[count] = 'A' + tmp-10;
			}
        	        tempNum /= base;
        	        count ++;
        	}
        	str[count] = '\0';
		reverseString(str + start);
	}
	return str;	
}

char* uitoa(const unsigned int number, char* str, size_t base)
{
		int tempNum = number;
		size_t count = 0;
        	while(tempNum > 0)
        	{
        	        int tmp = tempNum % base;
        	        str[count] = '0' + tmp;
        	        tempNum /= base;
        	        count ++;
        	}
        	str[count] = '\0';
		reverseString(str);
		return str;
	
}


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


// not the safest way to get the length of a string
// since there's the possibility that the string is not
// zero terminated. 
size_t strlen(const char * data)
{
	if(data[0] == '\0')
	{
		return 0;
	}
	size_t i = 0;
	for(i = 0; data[i]; i ++)
	{}
	return i;
}

char* memcpy(char * dest, const char * src, size_t length)
{

	unsigned long * dl = (unsigned long *) dest;
	const unsigned long * sl = (const unsigned long *) src;
	unsigned int llen = length / 4;
	for(size_t i = 0; i < llen; i ++)
	{
		dl[i] = sl[i];
	}

	length -= (size_t) (llen * 4);
        for(size_t i = 0; i < length; i ++)
        {
                dest[i] = src[i];
        }
        return dest;
}

void* memset(char* dest, const char val, size_t length)
{
        for(size_t i = 0; i < length; i ++)
        {
                dest[i] = val;
        }
        return dest;
}


