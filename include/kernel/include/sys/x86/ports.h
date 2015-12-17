#ifndef _SYS_X86_PORTS_H
#define _SYS_X86_PORTS_H
#include <sys.h>
void NMIEnable(void);
void NMIDisable(void);
void cli(void);
void sti(void);
#endif
