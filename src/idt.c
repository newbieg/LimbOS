// following this tutorial section on IDT http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
//

#include <system.h>
#include <idt.h>

extern void idt_flush(unsigned int);

void init_idt();
void idt_set_gate(unsigned char, unsigned int, unsigned short, unsigned char);

struct idt_entry idt[256];
struct idt_ptr idtpr;

void idt_install()
{
	idtpr.limit = sizeof(struct idt_entry) * 256 -1;
	idtpr.base = (unsigned int) & idt;
	memset((char*) &idt, 0, sizeof(struct idt_entry) * 256);

	idt_set_gate(0, (unsigned int) isr0, 0x08, 0x8E);
	idt_set_gate(1, (unsigned int) isr1, 0x08, 0x8E);
	idt_set_gate(32, (unsigned int) isr32, 0x08, 0x8E);

	idt_flush((unsigned int) &idtpr);
}

void idt_set_gate(unsigned char num, unsigned int base, unsigned short sel, unsigned char flags)
{
	idt[num].base_low = base & 0xFFFF;
	idt[num].base_high = (base >> 16) & 0xFFFF;

	idt[num].sellector = sel;
	idt[num].zero = 0;
	idt[num].flags = flags /* | 0x60*/;
}


