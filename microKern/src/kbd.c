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
		case N4:
			return '4';
		break;
		case N5:
			return '5';
		break;
		case N6:
			return '6';
		break;
		case N7:
			return '7';
		break;
		case N8:
			return '8';
		break;
		case N9:
			return '9';
		break;
		case N0:
			return '0';
		break;
		case MINUS:
			return '-';
		break;
		case EQU:
			return '=';
		break;
		case BKSP:
			return -2;
		break;
		case q:
			return 'q';
		break;
		case w:
			return 'w';
		break;
		case e:
			return 'e';
		break;
		case r:
			return 'r';
		break;
		case t:
			return 't';
		break;
		case y:
			return 'y';
		break;
		case u:
			return 'u';
		break;
		case i:
			return 'i';
		break;
		case o:
			return 'o';
		break;
		case p:
			return 'p';
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
