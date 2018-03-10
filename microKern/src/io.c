 /* Think of pos as a one-D representation of a two-D array.
  * y * width + x is the general idea. Not a fully protected function
  * user must beware, do not overflow your position buffer.
  * */

void vga_moveCursor(unsigned short pos)
{
	outb(FB_CMD_PORT, FB_CMD_HIGHBYTE);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_CMD_PORT, FB_CMD_LOWBYTE);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

