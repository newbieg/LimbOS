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
	idt_set_gate(2, (unsigned int) isr2, 0x08, 0x8E);
	idt_set_gate(3, (unsigned int) isr3, 0x08, 0x8E);
	idt_set_gate(4, (unsigned int) isr4, 0x08, 0x8E);
	idt_set_gate(5, (unsigned int) isr5, 0x08, 0x8E);
	idt_set_gate(6, (unsigned int) isr6, 0x08, 0x8E);
	idt_set_gate(7, (unsigned int) isr7, 0x08, 0x8E);
	idt_set_gate(8, (unsigned int) isr8, 0x08, 0x8E);
	idt_set_gate(9, (unsigned int) isr9, 0x08, 0x8E);
	idt_set_gate(10, (unsigned int) isr10, 0x08, 0x8E);
	idt_set_gate(11, (unsigned int) isr11, 0x08, 0x8E);
	idt_set_gate(12, (unsigned int) isr12, 0x08, 0x8E);
	idt_set_gate(13, (unsigned int) isr13, 0x08, 0x8E);
	idt_set_gate(14, (unsigned int) isr14, 0x08, 0x8E);
	idt_set_gate(15, (unsigned int) isr15, 0x08, 0x8E);
	idt_set_gate(16, (unsigned int) isr16, 0x08, 0x8E);
	idt_set_gate(17, (unsigned int) isr17, 0x08, 0x8E);
	idt_set_gate(18, (unsigned int) isr18, 0x08, 0x8E);
	idt_set_gate(19, (unsigned int) isr19, 0x08, 0x8E);
	idt_set_gate(20, (unsigned int) isr20, 0x08, 0x8E);
	idt_set_gate(21, (unsigned int) isr21, 0x08, 0x8E);
	idt_set_gate(22, (unsigned int) isr22, 0x08, 0x8E);
	idt_set_gate(23, (unsigned int) isr23, 0x08, 0x8E);
	idt_set_gate(24, (unsigned int) isr24, 0x08, 0x8E);
	idt_set_gate(25, (unsigned int) isr25, 0x08, 0x8E);
	idt_set_gate(26, (unsigned int) isr26, 0x08, 0x8E);
	idt_set_gate(27, (unsigned int) isr27, 0x08, 0x8E);
	idt_set_gate(28, (unsigned int) isr28, 0x08, 0x8E);
	idt_set_gate(29, (unsigned int) isr29, 0x08, 0x8E);
	idt_set_gate(30, (unsigned int) isr30, 0x08, 0x8E);
	idt_set_gate(31, (unsigned int) isr31, 0x08, 0x8E);

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


