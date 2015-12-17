/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * memory.h																	*
 *																			*
 * Memory management and utility functions.									*
 *																			*
\***************************************************************************/

#ifndef MEM_H
#define MEM_H

#include <multiboot.h>

// memset, sets a range of memory
void memset( void* ptr, unsigned char dat, int len );

// memcpy, copies a block of data
extern "C" void *memcpy( void *dest, const void *src, int n );

// memory management

// allocates space
void* kmalloc( uint_t );

// reallocates memory
void* krealloc( void*, uint_t );

// frees space
void kfree( void* );

// initializes paging
void InitPaging();

#endif
