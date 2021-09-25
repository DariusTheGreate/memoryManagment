#include "linearAllocator.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

linear_allocator* create_linear_allocator(const uint32_t buffer_init_size){
	void* handle = calloc(ALIGN(buffer_init_size), 1);
	if(handle == NULL){
		printf("linear allocator memory allocation returns NULL\n");
		exit(EXIT_FAILURE);
	}

	linear_allocator* la = calloc(sizeof(linear_allocator), 1);
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
	printf("%d, %d => ", handle, la -> buffer_size);
	if(ALIGN(size) > la -> buffer_size){
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
	free(la -> buffer_start);
	free(la);	
}
