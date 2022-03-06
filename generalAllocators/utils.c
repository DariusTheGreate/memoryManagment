#include "utils.h"
#include <cstdlib>
#include "stdio.h"
#include "pthread.h"
#include <string.h>
#include "unistd.h"

typedef char ALIGN[32];

typedef union block block_t;

union block{
	struct{
		size_t size;
		unsigned is_free;
		block_t* next;
	} info;
	ALIGN stub;
};

block_t *head = NULL;

block_t *tail = NULL;

pthread_mutex_t global_mutex;

block_t* get_free_block(size_t size_in){
	block_t* curr = head;
	while(curr){
		if(curr -> info.is_free && curr -> info.size >= size_in)
			return curr;
		curr = curr -> info.next;
	}
	return NULL;
}

void* my_malloc(size_t size_in){
	if(!size_in)
		return NULL;
	void* res;
	pthread_mutex_lock(&global_mutex);
	block_t* block = get_free_block(size_in);
	
	if(block){
		block -> info.is_free = 0;
		pthread_mutex_unlock(&global_mutex);
		return (void*)(block + 1);
	}

	size_t total_size = sizeof(block_t) + size_in;

	res = sbrk(total_size);

	if(res == (void*)(-1)){
		pthread_mutex_unlock(&global_mutex);
		return NULL;
	}

	block = (block_t*)res;
	block -> info.is_free = 1;
	block -> info.next = NULL;
	block -> info.size = size_in;

	if(!head)
		head = block;
	if(tail)
		tail -> info.next = block;
	tail = block;
	
	pthread_mutex_unlock(&global_mutex);
	//printf("\nin malloc -> %ld\n",(long int)((void*)(block + 1)));
	return (void*)(block + 1);
}

void my_free(void* ptr){
	//printf("\nin free -> %ld\n",(long int)ptr);
	if(!ptr)
		return;
	block_t* ptr_block = (block_t*)ptr - 1;
	void* programbreak = sbrk(0);
	if((char*)ptr + (ptr_block -> info.size) == programbreak){
		if(head == tail)
			head = tail = NULL;
		else{
			block_t* tmp = head;
			while(tmp){
				if(tmp -> info.next == tail){
					tmp -> info.next = NULL;
					tail = tmp;
				}
				tmp = tmp -> info.next;
			}
		}
		sbrk(0 - sizeof(block_t) - (ptr_block -> info.size));
		return;
	}

	ptr_block -> info.is_free = 1;
}

void *my_calloc(size_t num, size_t nsize)
{
	size_t size;
	void *block;
	if (!num || !nsize)
		return NULL;
	size = num * nsize;
	
	if (nsize != size / num)
		return NULL;
	
	block = my_malloc(size);
	
	if (!block)
		return NULL;
	
	memset(block, 0, size);
	
	return block;
}

void* safe_malloc(uint32_t size){
    printf("safe malloc\n");
	void* handle = my_malloc(size);
	if(handle == NULL){
		printf("allocation terminated\n");
		//exit(EXIT_FAILURE);
	}
	return handle;
}

void* safe_calloc(uint32_t size){
    printf("safe calloc\n");
	void* handle = my_calloc(size, 1);
	if(handle == NULL){
		printf("allocation terminated\n");
		//exit(EXIT_FAILURE);
	}
	return handle;
}

void safe_free(void* ptr){
    printf("safe free\n");
	my_free(ptr);
	//printf("free ends");
}
