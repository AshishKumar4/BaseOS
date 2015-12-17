/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * console.h																*
 *																			*
 * Console I/O, and simple text manipulation								*
 *																			*
\***************************************************************************/

#ifndef CONSOLE_H
#define CONSOLE_H

// handles all console i/o
class Console
{
	public:
		Console();
		~Console();
		
		void ToggleDebugMode()
		{
			indebugmode = !indebugmode;
		}
		
		void Output( const char* data );
		void Output( const char* data, bool debug );
		
		int Get( char* dest, int max );
		
		void ClearScreen();
		
	private:
		unsigned int m_x,m_y;
		unsigned char attrib;
		bool indebugmode;

		void PutC( char data );
		void MoveCursor();
};

// global console
extern Console cons;

#endif
