/***************************************************************************\
 * The Mattise Kernel														*
 * Copyright 2007 Matthew Iselin											*
 * Licensed under the GPL													*
 *																			*
 * vga.h																	*
 *																			*
 * Puts stuff onto the screen.												*
 *																			*
\***************************************************************************/

#ifndef VGA_H
#define VGA_H

#include <system.h>

// enters a VBE mode, returns the LFB address
uint_t EnterVesaMode( ushort_t xres, ushort_t yres, ushort_t bpp );

// vga class
class VGA {
	public:
		VGA();
		VGA( uint_t lfb );
		~VGA();
		
		void SetPixel( uint_t x, uint_t y, uint_t color );
		
		void EnterVGAMode( ushort_t xres, ushort_t yres, ushort_t bpp );
		
		void SetBgColor( unsigned int col );
		
		uint_t GetXRes();
		uint_t GetYRes();
		uint_t GetBPP();
		
		void ClearScreen();
		
		void Rectangle( uint_t x, uint_t y, uint_t w, uint_t h, uint_t color );
		void Line( uint_t x1, uint_t y1, uint_t x2, uint_t y2, uint_t color );
		
		uint_t* DrawCursor( uchar_t* data, uint_t x, uint_t y, uint_t w, uint_t h );
		void DrawBitmap( uchar_t* data, uint_t x, uint_t y, uint_t w, uint_t h, uint_t isbmp );
		void DrawBitmap( uint_t* data, uint_t x, uint_t y, uint_t w, uint_t h );
		void DrawBitmap( uint_t* data, uint_t x, uint_t y, uint_t w, uint_t h, uint_t colorkey );
		
		void BlitToScreen();
		
		int DrawText( int x, int y, char* txt, int len, uint_t color );
		
		/** window functions **/
		void DrawWindow( int x, int y, int w, int h, char* str, int len );
		
	private:
	
		uint_t m_dbuff;
		uint_t m_lfb;
		uint_t m_width;
		uint_t m_height;
		uint_t m_bpp;
		unsigned int m_bgcol;
};

// this creates a 24-bit color - use also in 32-bit
#define RGB( r, g, b ) ( (unsigned int) ( ( (char) r ) << 16 ) | ( ( ( char ) g ) << 8 ) | ( ( char ) b ) )
#define RGBA( r, g, b, a ) ( (unsigned int) ( ( ( char ) r << 24 ) ) | ( ( (char) g ) << 16 ) | ( ( ( char ) b ) << 8 ) | ( ( char ) a ) )

// common colors
#define COLOR_BLACK		0x000000
#define COLOR_WHITE		0xFFFFFF
#define COLOR_RED		0xFF0000
#define COLOR_GREEN		0x00FF00
#define COLOR_BLUE		0x0000FF
#define COLOR_GRAY		0x999999

#endif
