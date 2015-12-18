#include "interrupt.h"
#include "init_interrupts.h"
#include "io.h"
#include "stdio.h"

char *exceptions[]=
{
        "Divide by Zero",
        "Debug",
        "Non Maskable Interrupt",
        "Breakpoint",
        "Interrupt on Overflow",
        "Array Bounds Error",
        "Illegal Opcode",
        "Math not available",
        "Double Fault",
        "Math segment overflow",
        "Invalid TSS",
        "Segment not present",
        "Stack Fault",
        "General Protection Error",
        //"Page Fault",
        "na",
        "Math Error",
        "Alignment Error",
        "Machine Check"
};
void fault_handler(int num)
{
        struct fault_t regs;

		printf("\nException :: %s\n", exceptions[num]);

		printf("EAX: %d EBX: %d ECX: %d EDX: %d\n", regs.eax, regs.ebx, regs.ecx, regs.edx);
		printf("EDI: %d ESI: %d EBP: %d ESP: %d\n", regs.edi, regs.esi, regs.ebp, regs.esp);
		printf("GS: %d FS: %d ES: %d DS: %d\n", regs.gs, regs.fs, regs.es, regs.ds);
		printf("EIP: %d CS: %d EFLAGS: %d\n", regs.eip, regs.cs, regs.eflags);
		printf("Error code: %d\n", regs.errorcode);
asm volatile("cli"
		:
		:
		: "memory"		// Keep this exactly where we put it.
	);
		hlt();
}
