
#include <kernel/tty.h>
#include <mouse.c>
char bc=0;
int main()
{
    return 0;
}
void kernel_early(void)
{
    terminal_initialize();
    printf("Terminal Initialized! \n");
    kmalloc(1);
    printf("Heap Initialized! \n");
    gdtInit();
    printf("GDT Initialized \n");
    idtInit();
    printf("IDT Initialized \n");
    picInit(0x20, 0xA0);
    printf("PIC Initialized \n");
    //mouseinit();
    printf("Mouse Initialized \n");
    printf("Initializing VESA GUI Mode 1024 x 768 32000^3 colors");
    setVesa(0x117);
}
void kernel_start(void)
{
}
void kernel_main(void)
{
    RectD(0,0,1021,767,90,90,90);
    int i=10;
    while(1)
    {
        Creater(i);
        mouse_handler(MOUSE_HANDLE);
        i+=1;
        RectD(500,400,13,100,1000,1000,1000);
        RectD(200,400,13,100,1000,1000,1000);
        DBuff();
    }
}

