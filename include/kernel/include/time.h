/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * timer.h																	*
 *																			*
 * Hardware timer utilities, and the control center of the kernel: the		*
 * timer interrupt handler.													*
 *																			*
\***************************************************************************/

#ifndef TIME_H
#define TIME_H

void sleep( int seconds );
void delay( int ms );
unsigned int clock();

#endif
