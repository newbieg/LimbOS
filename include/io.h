#ifndef KERIODEFINED
#define KERIODEFINED

/* Functions used for kernel IO operations.
 * Attribution to "The little book about OS Development"
 * By: "Erik Helin and Adam Renberg"
 * currently most of these lines are a direct 1-1 copy...
 */

#define FB_CMD_PORT			0x3D4
#define FB_DATA_PORT			0x3D5
#define FB_CMD_HIGHBYTE			14
#define FB_CMD_LOWBYTE			15

// defined in src/tty.c
void vga_moveCursor(unsigned short pos);




// as far as I understand it, SERIAL_IO is basically just used for debugging purposes with bochs
// which is not my pref'd emulator anyhow, so this is left incomplete until I take it back on.
#define SERIAL_BASE_COM1	0x3F8
#define SERIAL_DATA_PORT(base)		(base)
#define SERIAL_FIFO_CMD_PORT(base)	(base + 2)
#define SERIAL_LINE_CMD_PORT(base)	(base + 3)
#define SERIAL_MODEM_CMD_PORT(base)	(base + 4)
#define SERIAL_LINESTATUS_CMD_PORT(base)	(base + 5)

#define SERIAL_LINE_ENABLE_DLAB		0x80

void serial_confBaudRate(unsigned short com, unsigned short divisor);
void serial_confLine(unsigned short com);

// defined in src/boot.s
extern void outb(unsigned short port, unsigned char data);
// the func's outw outl inw inl are to be implemented on an as-needed basis.
// currently just not needed.
// void outw(unsigned short port, unsigned short data);
// void outl(unsigned short port, unsigned int data);
extern unsigned char inb(unsigned short port);
// unsigned short inw(unsigned short port); 
// unsigned int inb(unsigned short port);

//defined in src/boot.s
// waits for an io to finish.
extern void io_wait();


extern void io_disableInterrupts();
extern void io_enableInterrupts();

char readKeyboard();


#endif
