#include <string.h>
void memset(void *_s, int _c, size_t _n)
{
    char *temp = (char*) _s;
    for ( ; _n != 0; _n--) {
		*temp++ = _c;
	}
}
