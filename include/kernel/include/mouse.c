
#include <gfx.c>
#include <gdt.c>
void mouse_wait(unsigned char type)
{
  unsigned int _time_out=100000;
  if(type==0)
  {
    while(_time_out--) //Data
    {
      if((inb(0x64) & 1)==1)
      {
        return;
      }
    }
    return;
  }
  else
  {
    while(_time_out--) //Signal
    {
      if((inb(0x64) & 2)==0)
      {
        return;
      }
    }
    return;
  }
}
void mouse_write(unsigned char a_write)
 {
 //Wait to be able to send a command
 mouse_wait(1);
 //Tell the mouse we are sending a command
 outb(0x64, 0xD4);
 //Wait for the final part
 mouse_wait(1);
 //Finally write
 outb(0x60, a_write);
 }
 unsigned char mouse_read()
 {
 //Get response from mouse
 mouse_wait(0);
 return inb(0x60);
 }
 void mouseinit()
{
    mouse_wait(1);
    outb(0x64,0xA8);
    mouse_wait(1);
    outb(0x64,0x20);
    unsigned char status_byte;
    mouse_wait(0);
    status_byte = (inb(0x60) | 2);
    mouse_wait(1);
    outb(0x64, 0x60);
    mouse_wait(1);
    outb(0x60, status_byte);
    mouse_write(0xF6);
    mouse_read();
    mouse_write(0xF4);
    mouse_read();
    MOUSE_HANDLE->int_no=12;
    mouse_handler(MOUSE_HANDLE);
    irqHandler(MOUSE_HANDLE);
}
int x=0,y=0;
 void mouse_handler(struct regs *r)
{
  static unsigned char cycle = 0;
  static char mouse_bytes[3];
  mouse_bytes[cycle++] = inb(0x60);

  if (cycle == 3) { // if we have all the 3 bytes...
    cycle = 0; // reset the counter
    // do what you wish with the bytes, this is just a sample
    if ((mouse_bytes[0] & 0x80) || (mouse_bytes[0] & 0x40))
      return; // the mouse only sends information about overflowing, do not care about it and return
    if (!(mouse_bytes[0] & 0x20))
      y |= 0xFFFFFF00; //delta-y is a negative value
    if (!(mouse_bytes[0] & 0x10))
      x |= 0xFFFFFF00; //delta-x is a negative value
    if (mouse_bytes[0] & 0x4)
      RectD(100,100,100,100,1000,1000,1000);
    if (mouse_bytes[0] & 0x2)
      RectD(100,100,100,100,1000,1000,1000);
    if (mouse_bytes[0] & 0x1)
      RectD(100,100,100,100,1000,1000,1000);
    // do what you want here, just replace the puts's to execute an action for each button
    // to use the coordinate data, use mouse_bytes[1] for delta-x, and mouse_bytes[2] for delta-y
  }
}
