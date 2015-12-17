#include <string.h>

void *memcpy(void * _dest, const void *_src, size_t _n)
{
    char *sp = (char*) _src;
    char *dp = (char*) _dest;
    for(; _n != 0; _n--) {
		*dp++ = *sp++;
	}
	return _dest;
}
