#ifndef INCLUDE_INIT_INTERRUPTS_H
#define INCLUDE_INIT_INTERRUPTS_H

void init_interrupts(void);
void load_exceptions(void);

// Variable types
#define byte unsigned int
#define word unsigned short
#define dword unsigned long

void load_idt();                             // Sets up IDT by loading IDTR
void install_handlers(int number, void (*handler)(), dword dpl); // Add interrupt

// Interrupt types
#define INT_0 0x8E00                         // 1000111000000000 = present,ring0,int_gate
#define INT_3 0xEE00                         // 1110111000000000 = present,ring3,int_gate

// Structure for an interrupt
typedef struct
{
	word low_offset;                         // Low nibble of offset to handler of interrupt
	word selector;                           // GDT selector used
	word settings;                           // Settings for int
	word high_offset;                        // High nibble to handler code
}__attribute__ ((packed)) x86_interrupt;

// Structure for the IDTR
typedef struct
{
     word limit;                             // Limit or Size of IDT
     x86_interrupt *base;                    // A pointer to the base of the IDT
}__attribute__ ((packed)) idtr;

#endif
