/*
 * (c) 2014 Apollo Developers
 * interrupts.h - Uniform Interrupt Handler
 */

#include <sys/callback.h>
#include <sys/interrupt.h>
#include <sys/screen.h>

void_callback_arg_t interruptHandlers[256];

void interruptHandlerRegister(unsigned char _n, void_callback_arg_t _f)
{
	interruptHandlers[_n] = _f;		// Set function into the vector
}

void unhandledInterrupt(unsigned int _intNum, ...)
{
}
