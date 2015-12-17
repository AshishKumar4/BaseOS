/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * mt.cc																	*
 *																			*
 * Handles task creation, and also handles virtual mode interrupt calls.	*
 * Utility functions for common tasks.										*
 *																			*
\***************************************************************************/

// necessary includes
#include <system.h>
#include <memory.h>
#include <console.h>
#include <disk.h>
#include <task.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

// task states
#define TASK_ALIVE	1 // ie. if( process.status ) is true if alive
#define TASK_DEAD	0

// kernel stack - one for each process
char kstacks[1024][1024];

// process table
struct tagStruct ptable[1024]; // maximum 1024 processes

// current task pointer
struct tagStruct current_task[1];

// current pid
int pid = -1;

// gets the current pid
int currpid()
{
	return pid;
}

// first reschedule
int firstr = 1;

// enabled?
bool enabled = false;

// gets/sets the enabled state
bool mtenabled() { return enabled; };
void mtdisable() { enabled = false; };
void mtenable() { enabled = true; };

// initializes the list
void initmt()
{
	for( int i = 0; i < 1024; i++ )
		ptable[i].taskState = TASK_DEAD;
		
	// setup the first kernel stack
	current_task[0].kstack = (unsigned int) kstacks[0] + 1024;
}

// kills a process
void kill( int id )
{
	// take the process out of the list
	ptable[id].taskState = TASK_DEAD;
}

// waits for a process to finish execution
void WaitUntilComplete( int id )
{
	// wait until it's TASK_DEAD
	while( ptable[id].taskState != TASK_DEAD );
}

// sets a process' registers
void SetRegs( int p, struct regs* r )
{
	ptable[p].r.eax = r->eax;
	ptable[p].r.ebx = r->ebx;
	ptable[p].r.ecx = r->ecx;
	ptable[p].r.edx = r->edx;
	ptable[p].r.ebp = r->ebp;
	ptable[p].r.esp = r->esp;
	ptable[p].r.edi = r->edi;
	ptable[p].r.esi = r->esi;
}

// gets a process' registers
void GetRegs( int p, struct regs* r )
{
	r->eax = ptable[p].r.eax;
	r->ebx = ptable[p].r.ebx;
	r->ecx = ptable[p].r.ecx;
	r->edx = ptable[p].r.edx;
	r->ebp = ptable[p].r.ebp;
	r->esp = ptable[p].r.esp;
	r->esi = ptable[p].r.esi;
	r->edi = ptable[p].r.edi;
}

// executes a real-mode interrupt
void int_v86( uchar_t int_num, struct regs* r )
{
	// create space for it
	uchar_t* exc = (uchar_t*) 0x1000; /** TODO: dynamic allocation of space between 0x500 and 0x7C00 **/
	
	// fill in the necessary info
	*exc++ = 0xCD;
	*exc++ = int_num;
	*exc++ = 0xCD;
	*exc++ = 0x80; /** INT80 = kill task **/
	*exc++ = 0xEB;
	*exc++ = 0xFE;
	
	// create the task and wait for it to complete
	int p = CreateTask16bit( 0x1000, 1024, "Virtual 8086 Mode Task", r );
	
	// wait for it
	WaitUntilComplete( p );
	
	// done, so get the registers at time of ending
	r->eax = ptable[p].r.eax;
	r->ebx = ptable[p].r.ebx;
	r->ecx = ptable[p].r.ecx;
	r->edx = ptable[p].r.edx;
	r->esp = ptable[p].r.esp;
	r->ebp = ptable[p].r.ebp;
	r->esi = ptable[p].r.esi;
	r->edi = ptable[p].r.edi;
}

// called when a process exits
void die()
{	
	// take the process out of the list
	ptable[pid].taskState = TASK_DEAD;
	
	// eventually we will just not execute this
	while( true );
}

// rescheduler
void resched()
{
	// enabled?
	if( !enabled )
	{
		kprintf( "[MTSK] Multitasking disabled but resched() called.\n" );
		return;
	}
	
	// check that we can save - if so, save
	if( pid != -1 )
	{
		// do nothing, we'll fall through
	}
	else
	{
		if( ptable[0].taskState == TASK_ALIVE )
		{
			current_task[0].esp = ptable[0].esp;
			ptable[0].time = ptable[0].prio;
			pid = 0;
		}
		return;
	}
	
	// reselection cutoff
	ReselCutoff:
	
	// check that the process' timeslice is done
	if( ptable[pid].time <= 0 )
	{
		// save usermode's esp
		ptable[pid].ustack = current_task[0].ustack;
		
		// save the stack pointer
		ptable[pid].esp = current_task[0].esp;
		
		// reset the time
		ptable[pid].time = ptable[pid].prio;

		// find the next alive task
		int i;
		for( i = pid+1; i < 1024; i++ )
		{
			if( ptable[i].taskState == TASK_ALIVE )
			{
				break;
			}
		}
		
		// check that i is valid
		if( i == 1024 )
		{
			i = 0;
			
			if( ptable[i].taskState == TASK_DEAD )
			{
				return;
			}
		}
		
		// restore the base (so others can use it)
		current_task[0].base = ptable[i].base;
		
		// restore usermode's esp
		current_task[0].ustack = ptable[i].ustack;
		
		// restore the stack pointer
		current_task[0].esp = ptable[i].esp;
		
		// set the time
		ptable[i].time = ptable[i].prio;
		
		// set the new pid
		pid = i;
	}
	else
	{
		// see if it got killed
		if( ptable[pid].taskState == TASK_DEAD )
		{
			// clear the time
			ptable[pid].time = 0;
			
			// and do evil (got to be a better way than this!)
			goto ReselCutoff;
		}
		
		// decrease the timeslice
		ptable[pid].time--;
	}
}

// task creation intro
int task_prolog( unsigned int stack, const char* pname, unsigned int prio )
{
	// find a spare entry
	int i;
	for( i = 0; i < 1024; i++ )
	{
		if( ptable[i].taskState == TASK_DEAD )
			break;
	}

	// check for overflow
	if( i == 1024 )
	{
		// none found
		kprintf( "\n[MTSK] Couldn't create process, too many processes!\n" );
		
		// die
		return -1;
	}
	
	// fill the entry
	ptable[i].taskState = TASK_ALIVE;
	ptable[i].kstack = (unsigned int) kstacks[i] + 1024;
	ptable[i].prio = prio;
	ptable[i].time = 0;
	ptable[i].cr3 = 0;
	memcpy( ptable[i].pname, pname, strlen( pname ) );
	void* dat = kmalloc( stack );
	ptable[i].esp = (unsigned int) ((uint_t) dat) + stack;
	
	// return the index
	return i;
}

// creates a 16 bit task - sector 313 is one
int CreateTask16bit( unsigned int base, unsigned int stack, const char* pname, struct regs* r, unsigned int prio )
{
	// get a process
	int i = task_prolog( stack, pname, prio );
	
	// check
	if( i == -1 )
	{
		kprintf( "oops" );
		return -1;
	}

	// fill the stack
	unsigned int* esp = (unsigned int*) 0x2800;
	unsigned int* ustack = (unsigned int*) 0x2900;
	
	// entry and the id
	esp--; *esp = i; esp--;
	
	// return point
	*esp-- = (unsigned int) die;
	
	// v86 segments
	*esp-- = 0x20;
	*esp-- = 0x20;
	*esp-- = 0x20;
	*esp-- = 0x20;
	
	// base of the task - 16-bit
	*esp-- = 0x20;
	*esp-- = (unsigned int) ustack;
	*esp-- = 0x20202;
	*esp-- = 0;
	*esp-- = 0x1000;

	// error code and interrupt number
	*esp-- = 0; *esp-- = 0;
	
	// registers - 8 of them
	*esp-- = ptable[i].r.eax = r->eax;
	*esp-- = ptable[i].r.ecx = r->ecx;
	*esp-- = ptable[i].r.edx = r->edx;
	*esp-- = ptable[i].r.ebx = r->ebx;
	*esp-- = ptable[i].r.esp = r->esp;
	*esp-- = ptable[i].r.ebp = r->ebp;
	*esp-- = ptable[i].r.esi = r->esi;
	*esp-- = ptable[i].r.edi = r->edi;
	
	// KERNEL segments - 4 of them
	*esp-- = 0x10;
	*esp-- = 0x10;
	*esp-- = 0x10;
	*esp = 0x10;
	
	// save the pointer
	ptable[i].esp = (unsigned int) esp;
	ptable[i].ustack = (unsigned int) ustack;
	ptable[i].v8086 = true;
	ptable[i].base = 0x1000;
	
	// return the process's id
	return i;
}

// creates a new task (not 16-bit)
int CreateTask( unsigned int base, unsigned int stack, const char* pname, unsigned int prio )
{
	// get a process
	int i = task_prolog( stack, const_cast< char* >( pname ), prio );
	
	// check
	if( i == -1 )
	{
		kprintf( "oops" );
		return -1;
	}
	
	// save this pointer
	int topofstack = ptable[i].esp;

	// fill the stack
	unsigned int* esp = (unsigned int*) ptable[i].esp;
	
	// entry and the id
	esp--; *esp = i; esp--;
	
	// return point
	*esp-- = (unsigned int) die;
	
	// base of the task
	*esp-- = 0x202;
	*esp-- = 0x08;
	*esp-- = base;
	
	// error code and interrupt number
	*esp-- = 0; *esp-- = 0;
	
	// registers - 8 of them
	*esp-- = 0;
	*esp-- = 0;
	*esp-- = 0;
	*esp-- = 0;
	*esp-- = 0;
	*esp-- = 0;
	*esp-- = 0;
	*esp-- = 0;
	
	// segments - 4 of them
	*esp-- = 0x10;
	*esp-- = 0x10;
	*esp-- = 0x10;
	*esp = 0x10;
	
	// save the pointer
	ptable[i].esp = (unsigned int) esp;
	ptable[i].v8086 = false;
	ptable[i].base = base;
	
	// return the process's id
	return i;
}
