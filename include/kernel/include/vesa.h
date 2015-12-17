/*
 * vesa.h
 *
 * Copyright 2013 JS-OS <js@duck-squirell>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef V86
#define V86

//#include <system.h>

#define MAX_BUTTONS   10
#define MAX_CHILDREN   100

typedef struct component
{
  int x;
  int y;
  int width;
  int height;
  callback_type_t onMouseLeftClick;
} component_t;

typedef struct window
{
  char *name;
  int id;
  int parentid;
  int x;
  int y;
  int width;
  int height;
  u32int *data;
  float z;

  char *flag;
  component_t buttons[MAX_BUTTONS];
} window_t;


//Colors
#define WINDOW_COLOUR_BORDER               0x397D02

#define WINDOW_COLOUR_TOPBAR               0x83F52C
#define WINDOW_COLOUR_FOCUS_TOPBAR         0x7FFF00
#define WINDOW_COLOUR_TOPBAR_TEXT          0x397D02

#define WINDOW_COLOUR_BACKGROUND           0xC5E3BF

/*sets the vesa graphics*/
void setVesa(u32int mode);

#define 	VBE_DISPI_INDEX_ID               0x0
#define 	VBE_DISPI_INDEX_XRES             0x1
#define 	VBE_DISPI_INDEX_YRES             0x2
#define 	VBE_DISPI_INDEX_BPP              0x3
#define 	VBE_DISPI_INDEX_ENABLE           0x4
#define 	VBE_DISPI_INDEX_BANK             0x5
#define 	VBE_DISPI_INDEX_VIRT_WIDTH       0x6
#define 	VBE_DISPI_INDEX_VIRT_HEIGHT      0x7
#define 	VBE_DISPI_INDEX_X_OFFSET         0x8
#define 	VBE_DISPI_INDEX_Y_OFFSET         0x9
#define 	VBE_DISPI_INDEX_NB               0xa
#define 	VBE_DISPI_ID0                    0xB0C0
#define 	VBE_DISPI_ID1                    0xB0C1
#define 	VBE_DISPI_ID2                    0xB0C2
#define 	VBE_DISPI_DISABLED               0x00
#define 	VBE_DISPI_ENABLED                0x01
#define 	VBE_DISPI_LFB_ENABLED            0x40
#define 	VBE_DISPI_NOCLEARMEM             0x80
#define 	VBE_DISPI_LFB_PHYSICAL_ADDRESS   0xE0000000
#define   VBE_DISPI_IOPORT_INDEX           0x01CE
#define   VBE_DISPI_IOPORT_DATA            0x01CF



#endif
