#include "tty.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


int kernel_main()
{

	vga_init();
	vga_writeString("Hello World");

	return 0;
}
