#ifndef GDT_TABLE_H_DEF
#define GDT_TABLE_H_DEF
// GDT

// Set up a GDT entry.
void gdt_set_gate(int num, unsigned int base, unsigned int limit, unsigned char access, unsigned char gran);

// Called once to set up the system GDT.
void gdt_install();

void writeGDTSize();




#endif
