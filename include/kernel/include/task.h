/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * task.h																	*
 *																			*
 * Handles task creation, and also handles virtual mode interrupt calls.	*
 * Utility functions for common tasks.										*
 *																			*
\***************************************************************************/

#ifndef MULTITASK_H
#define MULTITASK_H

#include <system.h>
typedef int bool;
// initializes the lists
void initmt();

// rescheduler
void resched();

// creates a new task
int CreateTask( unsigned int base, unsigned int stack, const char* pname, unsigned int prio);//prio=10

// creates a 16 bit task - sector 313 is one
int CreateTask16bit( unsigned int base, unsigned int stack, const char* pname, struct regs* r, unsigned int prio);//prio=10

// waits for a process to finish execution
void WaitUntilComplete( int id );

// executes a real-mode interrupt
void int_v86( uchar_t int_num, struct regs* r );

// enabled states
bool mtenabled();
void mtdisable();
void mtenable();

// kills a process
void kill( int pid );

// gets the current pid
int currpid();

// sets a process' registers
void SetRegs( int p, struct regs* r );

// gets a process' registers
void GetRegs( int p, struct regs* r );

// task structure
struct tagStruct {
	unsigned int esp;		// stack pointer
	unsigned int kstack;	// kernel stack
	unsigned int cr3;		// cr3 - page directory

	unsigned int ustack;	// user stack

	unsigned int taskState;	// alive or dead?

	unsigned int prio;		// priority
	unsigned int time;		// time been executing

	unsigned int base;		// process base address

	char pname[64];			// process name

	bool v8086;				// is it a virtual mode task?

	struct regs r;			// registers for this task
};

// currently running task
extern struct tagStruct current_task[1];

// mutexes

// initializes a mutex, unlocked
bool NewMutex( bool* dat );

// locks a mutex
bool LockMutex( bool* dat );

// unlocks a mutex
bool UnlockMutex( bool* dat );

// waits for a mutex
void WaitMutex( bool* dat );

// ADDRESS TRANSLATION //

/* segment:offset pair */
typedef uint32_t FARPTR;
typedef uint32_t addr_t;

/* Make a FARPTR from a segment and an offset */
#define MK_FP(seg, off)    ((FARPTR) (((uint32_t) (seg) << 16) | (uint16_t) (off)))

/* Extract the segment part of a FARPTR */
#define FP_SEG(fp)        (((FARPTR) fp) >> 16)

/* Extract the offset part of a FARPTR */
#define FP_OFF(fp)        (((FARPTR) fp) & 0xffff)

/* Convert a segment:offset pair to a linear address */
#define FP_TO_LINEAR(seg, off) ((void*) ((((uint16_t) (seg)) << 4) + ((uint16_t) (off))))

// TSS //

// tss type
typedef volatile struct __tagTSS_t {
    unsigned short   link;
    unsigned short   link_h;

    unsigned int   esp0;
    unsigned short   ss0;
    unsigned short   ss0_h;

    unsigned int   esp1;
    unsigned short   ss1;
    unsigned short   ss1_h;

    unsigned int   esp2;
    unsigned short   ss2;
    unsigned short   ss2_h;

    unsigned int   cr3;
    unsigned int   eip;
    unsigned int   eflags;

    unsigned int   eax;
    unsigned int   ecx;
    unsigned int   edx;
    unsigned int    ebx;

    unsigned int   esp;
    unsigned int   ebp;

    unsigned int   esi;
    unsigned int   edi;

    unsigned short   es;
    unsigned short   es_h;

    unsigned short   cs;
    unsigned short   cs_h;

    unsigned short   ss;
    unsigned short   ss_h;

    unsigned short   ds;
    unsigned short   ds_h;

    unsigned short   fs;
    unsigned short   fs_h;

    unsigned short   gs;
    unsigned short   gs_h;

    unsigned short   ldt;
    unsigned short   ldt_h;

    unsigned short   trap;
    unsigned short   iomap;

} __attribute((packed)) TSS_t ;

// global TSS
extern TSS_t global_tss;

#endif
