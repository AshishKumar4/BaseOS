#include <string.h>


int memcmp(const void *_s1, const void *_s2, size_t _n)
{
	const unsigned char *us1 = (const unsigned char *)_s1;
	const unsigned char *us2 = (const unsigned char *)_s2;
	while(_n-- != 0) {
		if(*us1 != *us2){
			return (*us1 < *us2) ? -1 : +1;
		}
		us1++;
		us2++;
	}
	return 0;
}
