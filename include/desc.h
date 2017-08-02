struct gdt_entry_struct
{
	unsigned int limit_base_low;
	unsigned int base_access_gran_base;
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct sellector_struct
{
	unsigned short limit;
	unsigned int base;

} __attribute__((packed));
typedef  sellector_struct sellect_t

void init_desc_tables();



