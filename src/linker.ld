ENTRY(_start)

SECTIONS
{
	. = 4M;

	_kernel_physical_start = .;
	.btt :
	{
		boot.o (.multiboot)
		boot.o (.text)
	}
	.bro :
	{
		boot.o (.rodata)
	}
	.bdata :
	{
		boot.o (.data)
	}
	.bbss :
	{
		boot.o (.bss)
		boot.o (COMMON)
	}


	. = ALIGN(0x1000);
	_boot_end = .;

	offset = 0xFFFFFFFFFFFFF000;
	. += 0xFFFFFFFF80000000;
	_kernel_virtual_start = .;
	.text : AT(_boot_end)
	{
		*(.multiboot)
		*(.text)
	}
	. = ALIGN(0x1000);

	.rodata : AT ( (LOADADDR (.text) + SIZEOF(.text) + 0xFFF) & 0xFFFFFFFFFFFFF000 )
	{
		*(.rodata)
	}
	. = ALIGN(0x1000);

	.data : AT ( (LOADADDR (.rodata) + SIZEOF(.rodata) + 0xFFF) & offset )
	{
		*(.data)
	}
	. = ALIGN(0x1000);

	.bss : AT ( (LOADADDR (.data) + SIZEOF(.data) + 0xFFF) & offset )
	{
		*(COMMON)
		*(.bss)
	}

	_kernel_virtual_end = .;
	_kernel_physical_end = (LOADADDR (.bss) + SIZEOF(.bss) + 0xFFF) & offset;
}
