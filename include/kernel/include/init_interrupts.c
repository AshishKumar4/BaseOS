#include "8259.c"
#include "interrupt.h"
#include "init_interrupts.h"
#include "io.h"
#include "interrupt.h"
#include "exceptions.c"
void init_interrupts(void)
{
        // Initiate Re-map of Exceptions/Interrupts
	    init_pics();

		// Install Exception Handlers
		load_exceptions();

   		// Point the IDT register to our IDT array
		load_idt();

	   	// Enable Interrupts
		sti();
}

void load_exceptions(void)
{
   		/*install_handlers(0,  fault_handler, 0);	  // __isr00
		install_handlers(1,  fault_handler, 0);	  // __isr01
		install_handlers(2,  fault_handler, 0);   // __isr02
		install_handlers(3,  fault_handler, 0);	  // __isr03
		install_handlers(4,  fault_handler, 0);	  // __isr04
		install_handlers(5,  fault_handler, 0);   // __isr05
		install_handlers(6,  fault_handler, 0);	  // __isr06
		install_handlers(7,  fault_handler, 0);   // __isr07
		install_handlers(8,  fault_handler, 0);	  // __isr08
		install_handlers(9,  fault_handler, 0);   // __isr09
		install_handlers(10, fault_handler, 0);   // __isr10
		install_handlers(11, fault_handler, 0);   // __isr11
		install_handlers(12, fault_handler, 0);   // __isr12
		install_handlers(13, fault_handler, 0);   // __isr13
		install_handlers(14, fault_handler, 0);   // __isr14
		install_handlers(15, fault_handler, 0);   // __isr15
		install_handlers(16, fault_handler, 0);   // __isr16
		install_handlers(17, fault_handler, 0);   // __isr17*/
}

idtr IDTR;
x86_interrupt IDT[256]; // = (x86_interrupt*)0xD00;

void load_idt()
{
    idtInit();
}

void install_handlers(int number, void (*handler)(), dword dpl)
{
		word selector = 0x08;
		word settings;
		dword offset = (dword)handler;

		// Get CS selector
		asm volatile("movw %%cs,%0" :"=g"(selector));

		// Set settings options depending on dpl
		switch(dpl)
		{
	    case 0: settings = INT_0; break;
		case 1:
		case 2:
		case 3: settings = INT_3; break;
		}

		// Set actual values of int
		IDT[number].low_offset   = (offset & 0xFFFF);
		IDT[number].selector     = selector;
		IDT[number].settings     = settings;
		IDT[number].high_offset  = (offset >> 16);
}



