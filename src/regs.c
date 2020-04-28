#include <system.h>
#include <tty.h>

void printRegs()
{
	int reg[11];
	pushRegs(reg);
	vga_writeString("eax= ");
	vga_writeDec(reg[1]);
	vga_writeString(", ebx= ");
	vga_writeDec(reg[0]);
	vga_writeString(", ecx= ");
	vga_writeDec(reg[2]);
	vga_writeString(", edx= ");
	vga_writeDec(reg[3]);
	vga_putchar('\n');
	vga_writeString("edi= ");
	vga_writeDec(reg[4]);
	vga_writeString(", esi= ");
	vga_writeDec(reg[5]);
	vga_writeString(", esp= ");
	vga_writeDec(reg[6]);

}
