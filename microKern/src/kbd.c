#include <kbd_map.h>
#include <io.h>
#include <tty.h>

char translate(enum KEY num)
{
	if(((char)num) > 0)
	{
		// vga_writeDec(num);
		switch(num)
		{
		case null:
			return 0;
			break;
		case N1:
			return '1';
		break;
		case N2:
			return '2';
		break;
		case N3:
			return '3';
		break;
		default:
			return 'x';
		
		}
	}
	return 0;
}
char getKey()
{
	enum KEY key;
	enum KEY oldKey = readKeyboard();
	key = oldKey;

        while(key == oldKey)
        {
                key = readKeyboard();
        }
	return translate(key);
}
