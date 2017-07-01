// Currently following tutorial: http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html

struct idt_entry
{
	unsigned short base_low;
	unsigned short sellector;
	unsigned char zero;
	unsigned char flags;
	unsigned short base_high;
} __attribute__((packed));

struct idt_ptr
{
	unsigned short limit;
	unsigned int base;
} __attribute((packed));


void idt_install();

extern void isr0();
extern void isr31();
