#include "stdint.h"

#ifndef _ALIGMENT

#define WORD_T uint32_t

#define ALIGN(n) (n + sizeof(WORD_T) - 1) & ~(sizeof(WORD_T) - 1)

#endif

typedef struct stack_allocator_type {
	void* buffer_start;
	uint32_t buffer_size;
	uint32_t buffer_offset;

} stack_allocator;

stack_allocator* create_stack_allocator(const uint32_t buffer_init_size);

void* s_alloc(stack_allocator* sa, const uint32_t size);

void s_free(stack_allocator* sa);

void destroy_stack_allocator(stack_allocator* sa);
