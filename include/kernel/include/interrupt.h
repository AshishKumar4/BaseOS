#ifndef _INCLUDE_INTERRUPT_H_
#define _INCLUDE_INTERRUPT_H_

struct fault_t
{
		int gs;
		int fs;
		int es;
		int ds;
		int edi;
		int esi;
		int ebp;
		int esp;
		int ebx;
		int edx;
		int ecx;
		int eax;
		int errorcode;
		int eip;
		int cs;
		int eflags;
};

void divide_error(void);                // __isr0
void debug_exception(void);             // __isr1
void non_maskable_interrupt(void);      // __isr2
void breakpoint(void);                  // __isr3
void overflow(void);                    // __isr4
void bounds_check(void);                // __isr5
void invalid_opcode(void);              // __isr6
void coprocessor_not_available(void);   // __isr7
void double_fault(void);                // __isr8
void coprocessor_segment_overrun(void); // __isr9
void invalid_tss(void);                 // __isr10
void segment_not_present(void);         // __isr11
void stack_exception(void);             // __isr12
void general_protection_fault(void);    // __isr13
void page_fault(unsigned long cr2);     // __isr14
void reserved(void);                    // __isr15
void coprocessor_error(void);           // __isr16
void alignment_check(void);             // __isr17
void machine_check(void);               // __isr18

void fault_handler(int num);
#endif
