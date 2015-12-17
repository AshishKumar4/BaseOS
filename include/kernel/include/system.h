/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * system.h																	*
 *																			*
 * System core functions, defines and types.								*
 *																			*
\***************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

extern unsigned char inportb(unsigned short _port);
/* main.c ** end */


/* gdt.c */
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);


/* gdt.c ** end */

/* idt.c */
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

/* idt.c ** end */

/* isrc.c */
/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */
}*MOUSE_HANDLE;

// asm macros
#define INTELSYNTAX ( asm ( ".intel_syntax noprefix" ) )
#define ATTSYNTAX	( asm ( ".att_syntax" ) )

// installs the GDT
void gdt_install();

// installs the IDT
void idt_install();

// install the ISRs
void isrs_install();

// sets up IRQ mapping
void irq_install();

// installs the timer
void install_timer();

// installs an IRQ handler (will eventually allow shared irqs)
void irq_install_handler(int irq, void (*handler)(struct regs *r));

// uninstalls an IRQ handler
void irq_uninstall_handler(int irq);

// ACCESSORY FUNCTIONS //

// sets a gate in the IDT
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

// port out
void outportb( short port, char dat );
void outportw( short port, short dat );
void outportl( short port, int dat );

// port in
short inportw( short port );
int inportl( short port );

// CR register manipulation
unsigned int read_cr0();
void write_cr0( unsigned int cr0 );


typedef unsigned int uint_t;
extern void isrs_install();
/* isrc.c ** end */

/* irq.c */
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));

extern void irq_uninstall_handler(int irq);

extern void irq_install();

extern void irq_wait(int irq);
/* irq.c ** end */

/* kb.c */
#define BUFFERSIZE 100

extern char kbbuf[BUFFERSIZE];

extern int kbpos;

extern unsigned int shift;

extern unsigned int getc_on;

extern unsigned int gets_on;

extern unsigned int kbprint_on;

extern unsigned int cmd_on;

extern unsigned int login_on;

extern void keyboard_install();

extern void keyboard_handler(struct regs *r);
/* kb.c ** end */

/* scrn.c */
#define CSRX 0
#define CSRY 1

extern unsigned short screen_no_scroll;

extern unsigned short *textmemptr;

extern int csr_x;

extern int csr_y;

extern void cls(void);

extern void move_csr(void);

extern void scroll(void);

extern void i_video(void);

extern void i_hello(void);

/* scrn.c ** end */




/* win.c */
extern struct win *first_window;
extern struct win *currwin;

extern void scwin(struct win *window);

extern void drwin(struct win *window);

extern int mkwin(int x, int y, int x2, int y2); /* vytvoreni okna */

extern int rmwin(struct win *window); /* smazani okna */
/* win.c ** end*/


/* cmd.c */
extern void cmdexec();

extern void cmd_install();
/* cmd.c ** end */


/* timer.c */
extern void timer_install();

extern void stopwatch();

extern void sleep(int t);
/* timer.c ** end */

/* ps2mouse.c */
extern void ps2m_install();

extern unsigned char ps2m_bytes[3];
/* ps2mouse.c ** end */

/* menu.c */
#define MENUNAMELEN 25;
#define ROOTMENUSIZE 10;
#define MENUSIZE 50;

extern int menu_addentry(char *name, char *action, int rootmenu);

extern int menu_rementry(char *name);

extern void menu_install();

/* menu.c ** end */

/* paging and memory */

extern void i_paging();

extern void i_floppy();

/* floppies ** end */

extern void Shutdown();
// define null!
#ifndef NULL
#define NULL ((void*)0)
#endif

#endif
