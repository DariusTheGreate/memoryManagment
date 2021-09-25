#ifndef _ALIGMENT

#define WORD_T uint32_t

#define ALIGN(n) (n + sizeof(WORD_T) - 1) & ~(sizeof(WORD_T) - 1)

#endif

typedef struct pool_allocator_type {
	void* buffer_start;
	uint32_t buffer_size;
	simple_pointer_based_stack* stack;
} pool_allocator;

pool_allocator* create_pool_allocator(uint32_t buffer_init_size){
	
}

void* p_alloc(pool_allocator* la, uint32_t size);

void p_free(pool_allocator* la);

void destroy_pool_allocator(pool_allocator* la);

#endif
 	