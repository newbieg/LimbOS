#include "tty.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


int kernel_main()
{

	vga_init();
	vga_writeString("Hello World");
	vga_writeDec(10023);

	return 0;
}
