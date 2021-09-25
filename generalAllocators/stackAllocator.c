#include "stackAllocator.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

stack_allocator* create_stack_allocator(const uint32_t buffer_init_size){
	void* handle = calloc(ALIGN(buffer_init_size), 1);
	if(handle == NULL){
		printf("linear allocator memory allocation returns NULL\n");
		exit(EXIT_FAILURE);
	}

	stack_allocator* sa = calloc(sizeof(stack_allocator), 1);
	if(sa == NULL){
		printf("allocation of linear_allocator return NULL\n");
		exit(EXIT_FAILURE);
	}

	sa -> buffer_start = handle;
	sa -> buffer_size = ALIGN(buffer_init_size);
	sa -> buffer_offset = 0;

	return sa;
}

void* s_alloc(stack_allocator* sa, const uint32_t size){
	void* handle = (sa -> buffer_start + sa -> buffer_offset);
	printf("%d, %d => ", handle, sa -> buffer_size);
	if(ALIGN(size) > sa -> buffer_size){
		printf("linear allocator buffer size to small");
		exit(EXIT_FAILURE);
	}
	sa -> buffer_size -= ALIGN(size);
	sa -> buffer_offset += ALIGN(size);
	return handle;
}

void s_free(stack_allocator* sa){
	memset(sa -> buffer_start, 0, sa->buffer_offset);
}

void s_free_chunk(stack_allocator* sa, const uint32_t size){
	if(ALIGN(size) > sa -> buffer_offset){
		printf("trying to free chunk that to big\n");
		exit(EXIT_FAILURE);
	}
	sa -> buffer_size += ALIGN(size);
	sa -> buffer_offset -= ALIGN(size);	
}

void destroy_stack_allocator(stack_allocator* sa){
	s_free(sa);
	free(sa -> buffer_start);
	free(sa);	
}
