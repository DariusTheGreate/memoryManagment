#include "stackAllocator.h"
#ifndef _STACK_ALLOC_
#define _STACK_ALLoC_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

stack_allocator* create_stack_allocator(uint32_t buffer_init_size){
	void* handle = safe_calloc(ALIGN(buffer_init_size));

	stack_allocator* sa = (stack_allocator*)safe_calloc(sizeof(stack_allocator));

	sa -> buffer_start = handle;
	sa -> buffer_size = ALIGN(buffer_init_size);
	sa -> buffer_offset = 0;

	return sa;
}

void* s_alloc(stack_allocator* sa, uint32_t size){
	void* handle = (void*)((char*)(sa -> buffer_start) + (sa -> buffer_offset));

	if(!((sa -> buffer_size) - ALIGN(size))){
		printf("stack allocator buffer size to small");
		exit(EXIT_FAILURE);
	}

	sa -> buffer_size -= ALIGN(size);
	sa -> buffer_offset += ALIGN(size);

	return handle;
}

void s_free(stack_allocator* sa){
	memset(sa -> buffer_start, 0, sa->buffer_offset);
}

void s_free_chunk(stack_allocator* sa, uint32_t size){
	if(ALIGN(size) > sa -> buffer_offset){
		printf("trying to free chunk that to big\n");
		exit(EXIT_FAILURE);
	}

	sa -> buffer_size += ALIGN(size);
	sa -> buffer_offset -= ALIGN(size);	
}

void destroy_stack_allocator(stack_allocator* sa){
	s_free(sa);
	safe_free(sa -> buffer_start);
	safe_free(sa);	
}

#endif

