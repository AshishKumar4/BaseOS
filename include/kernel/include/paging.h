/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * paging.h																	*
 *																			*
 * (not used) Sets up paging.												*
 *																			*
\***************************************************************************/

// Control registers: read/write

// READ
unsigned int read_cr0();
unsigned int read_cr2();
unsigned int read_cr3();

// WRITE
void write_cr0( unsigned int cr0 );
void write_cr3( unsigned int cr3 );
