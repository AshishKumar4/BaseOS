#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
void *memcpy(void*, const void*, size_t);
void memset(void*, int, size_t);
int memcmp(const void*, const void*, size_t);
char *strchr(const char*, int);
size_t strspn(const char*, const char*);
size_t strcspn(const char*, const char*);
char *strtok(char*, const char*);
char *strstr(const char*, const char*);
size_t strlen(const char*);
int strcmp(const char*, const char*);
int strncmp(const char*, const char*, size_t);
char *strcpy(char*, const char*);
char *strcat(char*, const char*);
#ifdef __cplusplus
}
#endif

#endif
