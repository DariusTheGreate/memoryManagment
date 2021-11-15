#ifndef _UTILS_
#define _UTILS_

#include "stdint.h"

void* safe_malloc(uint32_t size);

void* safe_calloc(uint32_t size);

void safe_free(void* ptr);

#endif
