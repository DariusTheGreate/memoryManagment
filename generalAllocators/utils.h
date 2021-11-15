#ifndef _UTILS_
#define _UTILS_

#include "stdint.h"
#include <stddef.h>

void* my_malloc(size_t size);
void my_free(void* ptr);
void *my_calloc(size_t num, size_t nsize);

void* safe_malloc(uint32_t size);

void* safe_calloc(uint32_t size);

void safe_free(void* ptr);

#endif
