#include "io.h"

__inline__ unsigned inportb(unsigned port)
{
		unsigned ret_val;
		__asm__ __volatile__("inb %w1,%b0"	: "=a"(ret_val) : "d"(port));
		return ret_val;
}

__inline__ void outportb(unsigned port, unsigned val)
{
		__asm__ __volatile__("outb %b0,%w1" :: "a"(val), "d"(port));
}

__inline__ void sti()
{
		__asm__("sti");	  // Enable ints
}


__inline__ void hlt()
{
		__asm__("hlt");   // Halt the CPU
}

__inline__ void idle()
{
		cli();
		hlt();
}

__inline__ void reboot()
{
		int temp;

		// Get ready for reboot...flush the keyboard controller
		do
		{
			temp = inportb(0x64);

			if(temp & 1)
            {
				inportb(0x60);
            }
		}
		while(temp & 2);

		// Reboot the computer...
		outportb(0x64, 0xFE);
}

