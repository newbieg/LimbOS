/* Currently followingn the tutorial found here; http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
 * gdt has been giving me some trouble so far. */

#include <system.h>
#include <gdt.h>




extern void gdt_flush(gdt_entry_t 
