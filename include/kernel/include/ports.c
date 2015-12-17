#include <sys/x86/ports.h>

void NMIEnable(void)
/// The keyboard controller is an interesting microchip, read more about
/// it in the documentation.
// Port 0x70 is the keyboard controller port, first we read the current
// bit-mask and then we bitwise AND 0x7F to disable the NMI mask.
{
	outb(0x70, inb(0x70)&0x7F);
}

void NMIDisable(void)
// OR'ing bitwise 80 will turn on the bitmask for masking the NMI.
{
	outb(0x70, inb(0x70)|0x80);
}

inline void cli(void)
{
	asm volatile("cli"
		:
		:
		: "memory"		// Keep this exactly where we put it.
	);
}
inline void sti(void)
{
	asm volatile("sti"
		:
		:
		: "memory"
	);
}
