#ifndef _UTILS_
#define _UTILS_

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

void* safe_malloc(uint32_t size){
	void* handle = malloc(size);
	if(handle == NULL){
		printf("allocation terminated\n");
		exit(EXIT_FAILURE);
	}
	return handle;
}

void* safe_calloc(uint32_t size){
	void* handle = calloc(size, 1);
	if(handle == NULL){
		printf("allocation terminated\n");
		exit(EXIT_FAILURE);
	}
	return handle;
}


void safe_free(void* ptr){
	free(ptr);
}

#endif
