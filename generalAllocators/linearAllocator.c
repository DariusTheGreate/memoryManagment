#include "linearAllocator.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

linear_allocator* create_linear_allocator(uint32_t buffer_init_size){
	void* handle = safe_calloc(ALIGN(buffer_init_size));
	if(handle == NULL){
		printf("linear allocator memory allocation returns NULL\n");
		exit(EXIT_FAILURE);
	}

	linear_allocator* la = (linear_allocator*)safe_calloc(sizeof(linear_allocator));
	if(la == NULL){
		printf("allocation of linear_allocator return NULL\n");
		exit(EXIT_FAILURE);
	}

	la -> buffer_start = handle;
	la -> buffer_size = ALIGN(buffer_init_size);
	la -> buffer_offset = 0;

	return la;
}

void* l_alloc(linear_allocator* la, uint32_t size){
	void* handle = (la -> buffer_start + la -> buffer_offset);
	printf("%p, %d => ", handle, la -> buffer_size);
	if(!((la -> buffer_size) - ALIGN(size))){
		printf("linear allocator buffer size to small");
		exit(EXIT_FAILURE);
	}
	la -> buffer_size -= ALIGN(size);
	la -> buffer_offset += ALIGN(size);
	return handle;
}

void l_free(linear_allocator* la){
	memset(la -> buffer_start, 0, la->buffer_offset);
}

void destroy_linear_allocator(linear_allocator* la){
	l_free(la);
	safe_free(la -> buffer_start);
	safe_free(la);	
}
