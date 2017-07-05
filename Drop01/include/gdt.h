#ifndef GDT_TABLE_H_DEF
#define GDT_TABLE_H_DEF
// GDT

struct gdt_entry
{
	unsigned short limit_low;
	unsigned short base_low;
	unsigned char base_middle;
	unsigned char access;
	unsigned char granularity;
	unsigned char base_high;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry_t;

struct gdt_ptr
{
	unsigned short limit;
	unsigned int base;

} __attribute__((packed));




// Set up a GDT entry.
void gdt_set_gate(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran);

// Called once to set up the system GDT.
void gdt_install();

void writeGDTSize();




#endif
