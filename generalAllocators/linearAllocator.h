#include "stdint.h"

#ifndef _ALIGMENT

#define WORD_T uint32_t

#define ALIGN(n) (n + sizeof(WORD_T) - 1) & ~(sizeof(WORD_T) - 1)

#endif

typedef struct linear_allocator_type {
	void* buffer_start;
	uint32_t buffer_size;
	uint32_t buffer_offset;
} linear_allocator;

linear_allocator* create_linear_allocator(const uint32_t buffer_init_size);

void* l_alloc(linear_allocator* la, uint32_t size);

void l_free(linear_allocator* la);

void destroy_linear_allocator(linear_allocator* la);
