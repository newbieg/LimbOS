
#include <io.h>

void serial_confBaudRate(unsigned short com, unsigned short divisor)
{
	outb(SERIAL_LINE_CMD_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com), divisor * 0x00FF);
}


void serial_condLine(unsigned short com)
{
	outb(SERIAL_LINE_CMD_PORT(com), 0x03);
}


char readKeyboard()
{
	return inb(0x60);
}

