/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * io.h																		*
 *																			*
 * Device manager, handles low-level I/O and driver installation			*
 *																			*
\***************************************************************************/

#ifndef DEVMAN_H
#define DEVMAN_H

#include <system.h>

/*
 * New drivers MUST call InstallDevice FIRST, and then use the
 * descriptor returned by that for all functions relating to that
 * device later. Once a valid descriptor is retrieved,
 * InstallFunctions is called with all of the functions that
 * the driver uses (pass NULL if one isn't required).
 * DestroyDevice deletes the device.
 *
 */

//------------- Constants -------------//

// open
#define READONLY			0x1000
#define WRITEONLY			0x2000
#define READWRITE			(READONLY | WRITEONLY)

// seek
#define SEEK_SET			0
#define SEEK_END			1
#define SEEK_CUR			2

//------------- Types -------------//

// open function pointer type
typedef int (*OpenFunc)(char*,int);

// ioctl types
typedef int (*IOCtlIntFunc)(int,int,int);
typedef int (*IOCtlPtrFunc)(int,int,void*);

// read type
typedef int (*ReadFunc)(int,void*,uint_t);

// write type
typedef int (*WriteFunc)(int,void*,uint_t);

// seek type
typedef int (*LSeekFunc)(int,uint_t,int);

// getc type
typedef int (*GetCFunc)();

// putc type
typedef int (*PutCFunc)(int);

//------------- Global Routines -------------//

// returns a new file descriptor for the device
int open( const char* pathname, int flags );

// allows control of the device outside of the normal read/write
int ioctl( int fd, int request, int data );
int ioctl2( int fd, int request, void* ptr );
// reads bytes into buff
int read( int fd, void* buff, uint_t count );

// writes bytes from buff
int write( int fd, void* buff, uint_t count );

// seeks to a location in the device
int lseek( int fd, uint_t offset, int where );

// closes a descriptor
int close( int fd );

// gets a character
int getc( int fd );

// writes a character
int putc( int fd, int c );

//------------- Device Management -------------//

// gets the device name
void GetDeviceName( int fd, char* dest );

// gets the device id
int GetDeviceID( int fd );

// installs a new device, and returns an index for use later
int InstallDevice( const char* devname, int VendorID, int DeviceID );

// installs the functions necessary (takes pointers)
int InstallFunctions( int dev, IOCtlIntFunc devioctl_int, IOCtlPtrFunc devioctl_ptr, ReadFunc devread, WriteFunc devwrite, LSeekFunc devlseek, GetCFunc devgetc, PutCFunc devputc );

// destroys a device
int DestroyDevice( int dev );

// dumps all the devices installed
void DumpDevices();

#endif
