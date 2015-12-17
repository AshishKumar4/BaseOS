/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * paging.cc																*
 *																			*
 * (not used) Sets up paging.												*
 *																			*
\***************************************************************************/

#include <system.h>
#include <stdio.h>

/** UTILITY FUNCTIONS **/

// CR0
unsigned int read_cr0()
{
	unsigned int cr0;
	__asm__ __volatile__ ( "movl %%cr0,%%eax" : "=a" (cr0) );
	return cr0;
}
void write_cr0( unsigned int cr0 )
{
	__asm__ __volatile__ ( "movl %%eax,%%cr0" : : "a" (cr0) );
}

// CR2
unsigned int read_cr2()
{
	unsigned int cr2;
	__asm__ __volatile__ ( "movl %%cr2,%%eax" : "=a" (cr2) );
	return cr2;
}

// CR3
unsigned int read_cr3()
{
	unsigned int cr3;
	__asm__ __volatile__ ( "movl %%cr3,%%eax" : "=a" (cr3) );
	return cr3;
}
void write_cr3( unsigned int cr3 )
{
	__asm__ __volatile__ ( "movl %%eax,%%cr3" : : "a" (cr3) );
}

/** PAGING SETUP **/

// page directories and tables
ulong_t* pagedir = ( ulong_t* ) 0x9C000;
ulong_t* pagetab = ( ulong_t* ) 0x9D000;

// initializes paging, sets up the first 4MB for the kernel
void InitPaging()
{
	// necessary variables
	ulong_t address = 0;
	uint_t i;
	
	// map the first 4 MB, first 4K not available
	pagetab[0] = address | 2; // not present
	address += 4096;
	for( i = 1; i < 1024; i++ )
	{
		//kprintf( "Setting up entry at address 0x%8x to point to %d\n", (unsigned int) &pagetab[i], address );
		pagetab[i] = address | 3; // supervisor, r/w, present
		address += 4096; // 4 KB
	}
	
	// fill first entry of the page directory
	pagedir[0] = (unsigned int) pagetab;
	pagedir[0] = pagedir[0] | 3; // supervisor, r/w, present

	// the rest are not present
	for( i = 1; i < 1024; i++ )
		pagedir[i] = 0 | 2; // not present

	uint_t addr = 0xdeadbeef;
	( (ulong_t*) ( pagedir[addr >> 22] & 0xFFFFF000 ) )[ ( addr << 10 ) >> 22 ] = ( 1024 * 1024 * 2 ) | 3;

	// fill CR3 and CR0
	write_cr3( (unsigned int) pagedir ); // put page directory address into cr3
	write_cr0( read_cr0() | 0x80000000 ); // set paging bit to 1
	
	/** first 8MB is now identity mapped, NULL pointers will page fault **/
}
