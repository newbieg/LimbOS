#ifndef KERIODEFINED
#define KERIODEFINED

/* Functions used for kernel IO operations.
 * Attribution to "The little book about OS Development"
 * By: "Erik Helin and Adam Renberg"
 *
 */

#define FB_CMD_PORT			0x3D4
#define FB_DATA_PORT			0x3D5
#define FB_CMD_HIGHBYTE			14
#define FB_CMD_LOWBYTE			15

void vga_moveCursor(unsigned short pos);


#define SERIAL_BASE_COM1	0x3F8
#define SERIAL_DATA_PORT(base)		(base)
#define SERIAL_FIFO_CMD_PORT(base)	(base + 2)
#define SERIAL_LINE_CMD_PORT(base)	(base + 3)
#define SERIAL_MODEM_CMD_PORT(base)	(base + 4)
#define SERIAL_LINESTATUS_CMD_PORT(base)	(base + 5)

#define SERIAL_LINE_ENABLE_DLAB		0x80

void outb(unsigned short port, unsigned char data);


#endif
