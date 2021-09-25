#ifndef _SIMPLE_ARRAY_BASED_STACK_
#define _SIMPLE_ARRAY_BASED_STACK_

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//use intrusive stack here(?)

typedef struct simple_array_based_stack_{
	void* stack_buffer;
	uint32_t buffer_size;
	uint32_t buffer_offset;
	uint32_t object_size;
} simple_array_based_stack;

simple_array_based_stack* create_array_based_stack(uint32_t buffer_size, uint32_t object_size){
	uint8_t* buffer = (uint8_t*)calloc(sizeof(object_size), 1);
	simple_array_based_stack* stack = (simple_array_based_stack*)calloc(sizeof(simple_array_based_stack), 1);
	stack -> stack_buffer = buffer;
	stack -> buffer_size = buffer_size;
	stack -> object_size = object_size;
	stack -> buffer_offset = 0;
}

void push_array_based_stack(simple_array_based_stack* stack, void* object_ptr){
	if(stack -> buffer_size < stack -> buffer_offset + stack -> object_size){
		printf("unable to push_back ==> reallocate. Not Implemented yet\n");
		exit(EXIT_FAILURE);
	}

	void* last_item = (stack -> stack_buffer + stack -> buffer_offset);
	void* res = memcpy(last_item, object_ptr, stack -> object_size);
	if(res == NULL){
		printf("cant mem copy element in array based stack push_back()\n");
		exit(EXIT_FAILURE);
	}
	stack -> buffer_offset += stack -> object_size;
}

void* pop_array_based_stack(simple_array_based_stack* stack, void* dest){
	if(stack -> buffer_offset - stack -> object_size < 0){
		printf("unable to pop_back");
		exit(EXIT_FAILURE);
	}
	if(dest == NULL){
		printf("unable to pop_back cause dist is NULL");
		exit(EXIT_FAILURE);	
	}
	stack -> buffer_offset -= stack -> object_size;
	void* src = (void*)((stack -> stack_buffer) + (stack -> buffer_offset));

	return src;
}


#endif
