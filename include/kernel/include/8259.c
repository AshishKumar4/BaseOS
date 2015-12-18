#include "8259.h"
#include "io.c"

unsigned int irq_mask = 0xFFFF;

// init_pics(), The 8259 PIC chip re-maps the irqs to interrupt handlers
void init_pics(void)
{
        // ICW1
	    outportb(0x20, 0x11);
		outportb(0xA0, 0x11);

        // ICW2 : re-maps pics
		outportb(0x21, 0x20);  // Irqs 0-07 = ints 20h-27h
		outportb(0xA1, 0x28);  // Irqs 8-15 = ints 28h-2Fh

		// ICW3
		outportb(0x21, 0x04);
		outportb(0xA1, 0x02);

        // ICW4
		outportb(0x21, 0x01);
		outportb(0xA1, 0x01);

   		// Disable all exceptions/interrupts
		outportb(0x21, 0xFF);
		outportb(0xA1, 0xFF);
}

// Sends command to PIC to mask an IRQ
void enable_irq(unsigned short irq_number)
{
		irq_mask &= ~(1 << irq_number);
		if(irq_number >= 8)
			irq_mask &= ~(1 << 2);

			outportb(0x21, irq_mask & 0xFF);
			outportb(0xA1, (irq_mask >> 8) & 0xFF);
}

// Sends command to PIC to unmask an IRQ
void disable_irq(unsigned short irq_number)
{
		irq_mask |= (1 << irq_number);
		if((irq_mask & 0xFF00)==0xFF00);
			irq_mask |= (1 << 2);

			outportb(0x21, irq_mask & 0xFF);
			outportb(0xA1, (irq_mask >> 8) & 0xFF);
}
