/* The GDT is how the OS determines access rights to memory.
 * So far I have to confess to being a bit ignorant of its workings.
 * Credit must go to Bran's kernel dev tutorial found here:
 * 	http://www.osdever.net/bkerndev/Docs/gdt.htm
 */

#include <system.h> // prototypes for gdt_install() and gdt_set_gate()
#include <tty.h>
#include <gdt.h>

struct gdt_entry
{
	unsigned short limit_low;
	unsigned short base_low;
	unsigned char base_middle;
	unsigned char access;
	unsigned char granularity;
	unsigned char base_high;
} __attribute__ ((packed));


struct gdt_ptr
{
	unsigned short limit;
	unsigned int base;
} __attribute__ ((packed));


volatile struct gdt_entry gdt[3];
volatile struct gdt_ptr gp; 

extern void gdt_flush(struct gdt_ptr gp_input); // Defined in assembly: src/boot.s

void gdt_set_gate(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran)
{
	gdt[num].base_low = (unsigned short) (base & 0xFFFF);
	gdt[num].base_middle = (unsigned char) (base >> 16) & 0xFF;
	gdt[num].base_high = (unsigned char) (base >> 24) & 0xFF;

	gdt[num].limit_low = (unsigned short) (limit & 0xFFFF);
	gdt[num].granularity = (unsigned char) ((limit >> 16) & 0xF);
	gdt[num].granularity |= (unsigned char) (gran & 0xF0);
	gdt[num].access = access;
}

void gdt_install()
{
	gp.limit = ((sizeof(struct gdt_entry)) * 3) - 1;
	gp.base = (unsigned int) &gdt;
	gdt_set_gate(0,0,0,0,0); // null

	gdt_set_gate(1,0,0xFFFFFFFF, 0x9A, 0xCF); // data
	gdt_set_gate(2,0,0xFFFFFFFF, 0x92, 0xCF); // code

	gdt_flush(gp);
}


void writeGDTSize(struct gdt_ptr gp_input)
{
	vga_writeDec(sizeof(gp_input));
	vga_writeString("\nContents of gp.base = ");
	vga_writeDec(gp_input.base);
	vga_writeString("\nContents of gp.limit = ");
	vga_writeDec(gp_input.limit);

}


