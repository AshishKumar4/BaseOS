#ifndef INCLUDE_8259_H
#define INCLUDE_8259_H

// init_pics: Remap PICs
void init_pics(void);  

// PIC irq masking
void enable_irq(unsigned short irq);                 

// PIC irq unmasking
void disable_irq(unsigned short irq);                            

#endif



