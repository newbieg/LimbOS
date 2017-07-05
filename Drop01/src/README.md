# SRC - Source files;
This is where the .c, .cpp, and .S (gnu-as) files will be located. Headers are in the "include" folder in the parent directory.
Eventually I will break these up for further organization, but right now I'm leaving it simple.


File Documentation:

boot.s - our initial starting point, basically sets us up to enter kernel.c
gdt.c - a work in progress, following Bran's kernel and looking at other's versions of the GDT
kernel.c - Starting point for C-calls. 
math.c - some common-use math functions. (may eventually replace with a full implementation of the file.)
README.md - Hey, this file is now recursive! Or is this meta?
string.c - Common functions for dealing with char pointers
tty.c - a simple vga driver
