// Currently following http://www.jamesmolloy.co.uk/tutorial_html/5.-IRQs%20and%20the%20PIT.html

#include <timer.h>
#include <tty.h>
#include <idt.h>


unsigned int tick = 0;

static void timer_callback(registers_t reg)
{
	tick ++;
	vga_writeString("Tick: ");
	vga_writeDec(tick);
	vga_putchar('\n');
}

void init_timer(unsigned int freq)
{
	register_interrupt_handler(IRQ0, &timer_callback);
	unsigned int divisor = 1193180 / freq;
	out_b(0x43, 0x36);
	unsigned char l = (unsigned char) (divisor & 0xFF);
	unsigned char h = (unsigned char) ((divisor >> 8) & 0xFF);
	out_b(0x40, l);
	out_b(0x40, h);
}

