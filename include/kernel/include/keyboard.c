#include <pic.c>
char getScanCode()
{
    char c=0;
    do {
        if(inb(0x60)!=c)
        {
            c=inb(0x60);
            if(c>0)
                return c;
        }
        }while(1);
}
char *getchar()
{
    char a=getScanCode();
    if(a==0x1C)
        return "AB";
    else return "AB";
}
