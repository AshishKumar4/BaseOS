/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * mutex.cc																	*
 *																			*
 * Handles mutexes within the kernel.										*
 *																			*
\***************************************************************************/

#include <system.h>
#include <task.h>

// locked/unlocked
#define MUTEX_LOCKED	false
#define MUTEX_UNLOCKED	true

// initializes a mutex, unlocked
bool NewMutex( bool* dat )
{
	return (*dat = MUTEX_UNLOCKED);
}

// waits for a mutex
void WaitMutex( bool* dat )
{
	while( *dat == MUTEX_LOCKED );
}

// locks a mutex
bool LockMutex( bool* dat )
{
	// wait for it first
	WaitMutex( dat );
	
	// return the lock
	return (*dat = MUTEX_LOCKED);
}

// unlocks a mutex
bool UnlockMutex( bool* dat )
{
	// unlock it
	return (*dat = MUTEX_UNLOCKED);
}
